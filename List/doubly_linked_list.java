package DataStructures.List;


public class doubly_linked_list<E> {
	private Node head;
    private Node tail;
	private int size =0; //노드 개수
	
	//노드 클래스
	private class Node{
		private E data; //데이터 저장 필드
		private Node next=null; //해당 노드의 다음 노드. 
		private Node prev=null; //해당 노드의 이전 노드.
		
		public Node(E data) {
			this.data=data; //데이터 넣기.
		}
	}
	
//	리스트 끝에 노드 생성
	boolean add(E data){
		boolean addData = false;
		try {// 예외 발생 가능성 코드. 런타임 오류가 나서 노드를 생성 못했을 경우 false를 그대로 출력.
			Node newNode = new Node(data); 
			if(size==0) //첫번째 노드 생성
			{
				head=newNode;
				tail=newNode;
				size++;
			}else { //마지막 노드 생성
				tail.next = newNode;
				newNode.prev = tail;
				tail = newNode;
				size++;
			}
			addData = true;
		} catch (Exception e) {// 예외 발생 처리 코드
			System.out.println(e.toString());
		}
		return addData;
	}
	
//	해당 인덱스에 노드 생성
	public void add(int index, E data) {
		if(index>-1 && index<size) { 
			Node newNode = new Node(data);
			if(index==0) { //노드 있는데 head로 넣을때
				newNode.next=head;
				head.prev=newNode;
				head=newNode;
				size++;
			}else { //중간에 끼워넣을때
				Node tmp1 = node(index);
				Node tmp2 = node(index).prev;
				//오른쪽방향
				tmp2.next=newNode;
				newNode.next=tmp1;
				//왼쪽방향
				tmp1.prev=newNode;
				newNode.prev=tmp2;
				size++;
			}
		}else if(index==size){ //맨 마지막에 넣을때
			add(data); 
		}else {
			throw new IndexOutOfBoundsException("인덱스 범위를 벗어남");
		}
	}

//	모든 노드 삭제
	//근데 널로 두면 노드들 안에 있는 데이터는 어떻게 지우지?? 
	//c는 사용하지 않는 데이터를 사람이 지워야하는데, 자바는 가비지컬렉션이 안쓰는 영역을 알아서 해제해줌.
	//그래서 변수를 초기화시켜서 참조했던 주소 연결을 끊으면 알아서 처리해줌.
//	가비지컬렉션 : 동적 할당된 메모리 영역 가운데 더 이상 사용할 수 없게 된 영역을 탐지하여 자동으로 해제하는 기법.
	void clear() {
		head=null;
		tail=null;
		size=0;
	}
	
//	Returns true if this list contains the specified element.
	boolean contains(E data) {
		boolean isData = false;
		for(int i=0; i<size; i++)
		{
			if(node(i).data.equals(data)) {
				isData=true;
			}
		}
		return isData;
	}
	
//	인덱스에 들어있는 데이터 반환.
	public E get(int index) {
		return node(index).data;
	}
	
	//해당 인덱스에 있는 노드 반환.
	private Node node(int index) {
		Node indexNode=null;
		if(index>-1 && index<size) {
			if (index < size / 2) {
				indexNode= head;
				for(int i=0; i<index;i++){
					indexNode = indexNode.next;
				}
			}else {
				indexNode= tail;
				for(int i=size-1; i>index; i--){
					indexNode = indexNode.prev;
				}
			}
		}else {
			throw new IndexOutOfBoundsException("인덱스 범위를 벗어남");
		}
		return indexNode;
	}
	
//	지정된 위치에 있는 data를 바꿈.
	public E set(int index, E data) {
		E dataPrev= node(index).data;
		node(index).data=data;
		//지정된 위치에 있던 이전 요소 반환.
		return dataPrev;
	}
	
//	해당 데이터가 첫번째로 있는 노드 인덱스 반환. 해당 데이터 없으면 -1반환.
	public int indexOf(E data) {
		int dataNodeIndex = -1;
		Node indexNode= head;
		for(int i=0; i<size;i++){
			if(indexNode.data.equals(data)) {
				dataNodeIndex=i;
				break;
			}				
			indexNode = indexNode.next;
		}
		return dataNodeIndex;
	}
	
//	해당 데이터가 마지막으로 있는 노드 인덱스 반환. 해당 데이터 없으면 -1반환.
	public int lastIndexOf(E data) {
		int dataNodeIndex = -1;
		Node indexNode= tail;
		for(int i=size-1; i>dataNodeIndex;i--){
			if(indexNode.data.equals(data)) {
				dataNodeIndex=i;
				break;
			}				
			indexNode = indexNode.prev;
		}
		return dataNodeIndex;
	}
	
//	노드 없으면 true. 삼항연산자를 사용해서 한 줄로 적을 수 있음.
	public boolean isEmpty() {
		return size==0 ? true : false;
	}
	
//	지정된 위치 노드 제거. 제거된 노드의 데이터 반환
	public E remove(int index) {
		Node indexNode = node(index);
		if(index>-1 && index<size) {
			if(size==1) { //맨 앞 노드제거
				clear();
			}else if(index==0) { //맨 앞 노드제거
				node(1).prev=null; 
				head=node(1);
			}else if(indexNode==tail) { //마지막 노드 제거
				node(index-1).next=null;
				tail=node(index-1);
			}else{ //중간노드 제거
				node(index-1).next=node(index+1);
				node(index+1).prev=node(index-1);
			}
			size--;
		}else { //해당 인덱스 노드 없음.
			throw new IndexOutOfBoundsException("인덱스 범위를 벗어남");
		}
		return indexNode.data;
	}
	
	//노드 개수
	public int size() {
		return size; 
	}
}