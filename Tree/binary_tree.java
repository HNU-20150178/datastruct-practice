package DataStructures.Tree;
class TreeNode {
    private int itsKey;
    private Object itsValue;
    private TreeNode nodes[] = new TreeNode[2];

    public TreeNode(int key, Object itsValue){
        this.itsKey=key;
        this.itsValue=itsValue;
        System.out.println("start TreeMapNode");
    }
    public Object find(int key){
        if(key==this.itsKey){
            return this.itsValue;
        }
        return findSub(selectSubNode(key),key);
    }
    private int selectSubNode(int key){
        return (key<itsKey)?0:1;
    }

    private Object findSub(int node, int key){
        return nodes[node]==null?null:nodes[node].find(key);
    }
    public void add(int key, Object value){
        if(key == itsKey){
            itsValue = value;
        }else{
            SubNode(selectSubNode(key),key,value);
        }
    }
    private void SubNode(int node, int key, Object value){
        if(nodes[node]==null){
            nodes[node] = new TreeNode(key,value);
        }else{
            nodes[node].add(key, value);
        }
    }

}

class Tree { 

	TreeNode topNode=null; 
	public void add(int key,Object value) { 

	if(topNode==null) 
		topNode=new TreeNode(key, value); 
	else 
		topNode.add(key, value); 
	} 
	public Object get(int key) { 
		return topNode==null ? null:topNode.find(key); 
	}
}

public class binary_tree {
    public static void main(String[] args){
        Tree TM = new Tree();
        TM.add(1, "KIM");
        TM.add(2, "LEE");
        TM.add(3, "YOON");

        System.out.println("Data Sarch and Get..");
        Object Temp = TM.get(1);
        System.out.println(Temp);


        System.out.println("Data Sarch and Get..");
        Object Temp2 = TM.get(2);
        System.out.println(Temp2);
    }
}