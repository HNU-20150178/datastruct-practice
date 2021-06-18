package DataStructures.List;

import java.util.LinkedList;

public class single_linked_list {
	public static void main(String[] args) {
		LinkedList<Integer> llist = new LinkedList<Integer>();	
	    llist.addFirst(1);
	    llist.addLast(2);
	    llist.add(3);
	    llist.add(1,10); //index 1 뒤에 10추가
	    
		
	    for(Integer i : llist) {
	    	System.out.println(i);
	    }
	    
	    llist.clear();

	}

}
