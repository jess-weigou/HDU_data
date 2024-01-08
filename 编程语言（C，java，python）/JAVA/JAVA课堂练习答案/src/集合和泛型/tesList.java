<<<<<<< HEAD
package 集合和泛型;
import java.util.*;
//String strBefor[] ={"1","2","4","6","2","4","3"};
public class tesList {

	public static void main(String[] args) {
	    HashSet<String>  hs=new HashSet<String>();
	    hs.add("hello");
	    hs.add("java");
	    hs.add("hello");
	    hs.add("hdu");
	   // al.add(1, "haha");
	   // al.remove(0);
	   // al.remove("hello");
	    
	  //  for(String i:hs)
	   // 	System.out.println(i);
		
		Iterator<String> it=hs.iterator();
		while(it.hasNext())
			System.out.println(it.next());
	    
//	    ArrayList<String>  al=new ArrayList<String>();
//	    al.add("hello");
//	    al.add("java");
//	    al.add("hello");
//	    al.add("hdu");
//	   // al.add(1, "haha");
//	   // al.remove(0);
//	    al.remove("hello");
////	    for(int i=0;i<al.size();i++)
////	    	System.out.println(al.get(i));
//	    for(String i:al)
//	    	System.out.println(i);
	}
}
=======
package 集合和泛型;
import java.util.*;
//String strBefor[] ={"1","2","4","6","2","4","3"};
public class tesList {

	public static void main(String[] args) {
	    HashSet<String>  hs=new HashSet<String>();
	    hs.add("hello");
	    hs.add("java");
	    hs.add("hello");
	    hs.add("hdu");
	   // al.add(1, "haha");
	   // al.remove(0);
	   // al.remove("hello");
	    
	  //  for(String i:hs)
	   // 	System.out.println(i);
		
		Iterator<String> it=hs.iterator();
		while(it.hasNext())
			System.out.println(it.next());
	    
//	    ArrayList<String>  al=new ArrayList<String>();
//	    al.add("hello");
//	    al.add("java");
//	    al.add("hello");
//	    al.add("hdu");
//	   // al.add(1, "haha");
//	   // al.remove(0);
//	    al.remove("hello");
////	    for(int i=0;i<al.size();i++)
////	    	System.out.println(al.get(i));
//	    for(String i:al)
//	    	System.out.println(i);
	}
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
