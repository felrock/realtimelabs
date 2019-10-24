package com.company;

public class PhilosophersDeadlock {
    private static int NUM_PHIL = 5;
    private static int DELAY_MS = 500;
    private static Object[] forks = new Object[NUM_PHIL];

    public static void main(String[] args) throws InterruptedException {
        Philosopher[] phils = new Philosopher[NUM_PHIL];
        System.out.println("Philosophers deadlock program..");
        // Create forks
        for(int i=0; i<NUM_PHIL; i++) forks[i]=new Object();
        for(int i=0; i<NUM_PHIL; i++) phils[i]=new Philosopher(i, forks[i], forks[(i+1) % NUM_PHIL]);
        // Start all Philosopher threads
        for(int i=0; i<NUM_PHIL; i++) phils[i].start();
        Thread.sleep(10000); // Idle here
        // Request termination
        for(int i=0; i<NUM_PHIL; i++) phils[i].terminate();
        // Wait for all to finish
        for(int i=0; i<NUM_PHIL; i++) phils[i].join();
        // Print stats
    }

    static class Philosopher extends Thread {
        private final Object leftFork, rightFork;
        private final int id;
        private boolean RUNNING;

        public Philosopher(int id, Object leftFork, Object rightFork) {
            // Constructor
            this.id = id;
            this. RUNNING = true;
            this.leftFork = leftFork;
            this.rightFork = rightFork;
        }

        private void eat() {
            System.out.println("Philosopher "+id+" is eating.");
            // delay
            try {
                Thread.sleep(1500);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void think() {
            System.out.println("Philosopher "+id+" is thinking.");
            // delay
            try {
                Thread.sleep(DELAY_MS);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void waiting(){
            System.out.println("Philosopher "+id+" is waiting.");
            // delay
            try {
                Thread.sleep(DELAY_MS);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void terminate(){
            RUNNING = false;
        }

        public void run( ) {
            while(RUNNING) {
                think();
                waiting();
                //Pick up forks
                synchronized (leftFork){
                    System.out.println("Philosopher "+id+" picked up left Fork");
                    synchronized (rightFork){
                        System.out.println("Philosopher "+id+" picked up right Fork");
                        eat();
                    }
                }
            }
        }
    }
}


