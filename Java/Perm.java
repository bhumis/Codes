// Description: The code generates all the subsets that can be formed using the elements in an array.

package codingpractise;

import java.util.*;

public class Perm {
	
	public static void calculateperm(int[] a)
	{
		ArrayList<LinkedList<HashSet>> l=new ArrayList<LinkedList<HashSet>>();
		
		for(int i=0; i<a.length; i++)
		{
			LinkedList l1=new LinkedList();
			
			if(l.isEmpty())
			{
				l1.add(0);
				l1.add(a[0]);
				l.add(l1);
			}
			// System.out.println("first subset is " + l1);
			else
			{
				LinkedList l2=l.get(i-1);
				l1.addAll(l2);
				for(int j=0; j<l2.size(); j++)
				{
					Set s1=new HashSet();
					s1.add(l2.get(j));
					s1.add(a[i]);
					l1.add(s1);
				}
				l.add(l1);
			}
		
		}
		
		System.out.println("elements are" + l.get(0));
		System.out.println("and are " + l.get(1));
		System.out.println(" and also are " + l.get(3));
	}

	public static void main(String[] args) {

		int[] arr={1,2,3,4};
		
		calculateperm(arr);
		
	}

}
