// The following code sorts a string array and puts all the anagrams together under same key in a Hashtable

package codingpractise;

import java.util.*;

public class SortStrings {

	public static String sortchars(String s1)
	{
		char[] c=s1.toCharArray();
		Arrays.sort(c);
		
		 return(new String(c));
		 
	}
	
	public static void main(String[] args) {

		
		String[] s={"bhumi","muskan","indu","bhmui","uskanm"};
		
		Hashtable<String, LinkedList<String>> h=new Hashtable<String, LinkedList<String>>();
		
		for(int i=0; i<s.length; i++)
		{
			String s2=sortchars(s[i]);
			if(h.containsKey(s2))
			{
				LinkedList<String> S=h.get(s2);
				S.add(s[i]);
				h.put(s2, S);
			}
			else
			{
				LinkedList<String> L=new LinkedList<String>();
				L.add(s[i]);
				h.put(s2, L);
				
			}
		}
		
		Enumeration E=h.elements();
		while(E.hasMoreElements())
		{
			System.out.println(E.nextElement());
		}
		
		
		LinkedList<Integer> n1=new LinkedList<Integer>();
		n1.add(1);
	}

}
