package com.company;

public class Philosophers {
    private static int NUM_PHIL = 8;
    private static Fork[] forks = new Fork[NUM_PHIL];

    public static void main(String[] args) throws InterruptedException {
        Philosopher[] phils = new Philosopher[NUM_PHIL];
        // Create forks
        for(int i=0; i<NUM_PHIL; i++) forks[i]=new Fork();
        //Create Philosophers
        for(int i=0; i<NUM_PHIL; i++) phils[i]=new Philosopher(i, forks[i], forks[(i+1) % NUM_PHIL]);
        // Start all Philosopher threads
        for(int i=0; i<NUM_PHIL; i++) phils[i].start();
        // Idle here
        Thread.sleep(20000);
        // Request termination
        for(int i=0; i<NUM_PHIL; i++) phils[i].terminate();
        // Wait for all to finish
        for(int i=0; i<NUM_PHIL; i++) phils[i].join();
        // Print stats
        System.out.println("Philosopher\t Eaten");
        for(int i=0; i<NUM_PHIL; i++){
            System.out.println(i + "\t\t" + phils[i].getEaten());
        }
    }

    static class Philosopher extends Thread {
        private final Fork leftFork, rightFork;
        private final int id;
        private int eaten = 0;
        private boolean RUNNING = true;

        public Philosopher(int id, Fork leftFork, Fork rightFork) {
            // Constructor
            this.id = id;
            this.leftFork = leftFork;
            this.rightFork = rightFork;
        }

        private int getEaten() {
            return eaten;
        }

        private void terminate() {
            RUNNING = false;
        }

        private void eat() {
            System.out.println("Philosopher "+id+" is eating.");
            eaten++;
            // delay
            try {
                Thread.sleep(1000);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void think() {
            System.out.println("Philosopher "+id+" is thinking.");
            // delay
            try {
                Thread.sleep(500);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void waiting(){
            System.out.println("Philosopher "+id+" is waiting.");
            // delay
            try {
                Thread.sleep(200);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        public void run( ) {
            while(RUNNING) {
                think();
                waiting();
                //Pick up forks
                try {
                    leftFork.grab();
                    rightFork.grab();
                    eat();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                // put down forks
                leftFork.release();
                rightFork.release();
            }
        }
    }
}

class Fork {
    private Thread philosopher = null;

    public synchronized void grab() throws InterruptedException {
        while (philosopher != null)
            wait();
        philosopher = Thread.currentThread();
    }

    public synchronized void release() {
        if (philosopher == Thread.currentThread())
            philosopher = null;
        notify();
    }
}
