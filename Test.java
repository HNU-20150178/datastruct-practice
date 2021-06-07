class A{
    public void test1(){
        System.out.println("A");   
    }
}
class B extends A{
    public void test2(){
        System.out.println("Test2");   
    }
}
public class Test{
    public static void main(String [] args){
       A a = new A();
       A b = new B();
       B b1 = new B();
       ((B)b).test2();
       b.test1();
      
    }
}
