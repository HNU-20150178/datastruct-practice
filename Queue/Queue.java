package Queue;

import java.util.LinkedList;

public class Queue {
    public static void main(String[] args){
        LinkedList<String> ls = new LinkedList<String>();

        ls.offer("a");
        ls.offer("b");
        ls.offer("c");
        ls.offer("d");

        System.out.println("Size = "+ ls.size());
        while(ls.peek() != null)
            System.out.println(ls.poll());
        System.out.println("Size = " + ls.size());
    }
}
