package Timetrans;

import java.io.IOException;
import java.util.HashMap;


public class Findtime {
	public static int[] findthetime(int[] A){
		HashMap<Integer,Integer> timesheet=new HashMap<>();
		HashMap<Integer,Integer> timesheets=new HashMap<>();
		for(int i=0;i<6;i++){
			timesheet.put(i, A[i]);
			timesheets.put(i, A[i]);
		}
		
		int[] early=new int[6];
		int[] late=new int[6];
		int maxmark=0;
		int minmark=0;
		
		maxmark=findhour_1(timesheet);
		if(maxmark==-1)return null;
		late[0]=A[maxmark];
		timesheet.remove(maxmark);
		
		minmark=findhour_2(timesheets);
		if(minmark==-1)return null;	
		early[0]=A[minmark];
		timesheets.remove(minmark);
	
		if(late[0]==2){
			maxmark=findsamllmax(timesheet);
			if(maxmark==-1)return null;
			late[1]=A[maxmark];
			timesheet.remove(maxmark);
		}
		if(late[0]<2){
			maxmark=findmax(timesheet);
			if(maxmark==-1)return null;
			late[1]=A[maxmark];
			timesheet.remove(maxmark);
		}
		
		if(early[0]==2){
			minmark=findsamllmin(timesheets);
			if(minmark==-1)return null;
			early[1]=A[minmark];
			timesheets.remove(minmark);
		}
		if(early[0]<2){
			minmark=findmin(timesheets);
			if(minmark==-1)return null;
			early[1]=A[minmark];
			timesheets.remove(minmark);
		}
		
		maxmark=findminutemax(timesheet);
		if(maxmark==-1)return null;
		late[2]=A[maxmark];
		timesheet.remove(maxmark);
		maxmark=findmax(timesheet);
		if(maxmark==-1)return null;
		late[3]=A[maxmark];
		timesheet.remove(maxmark);
		maxmark=findminutemax(timesheet);
		if(maxmark==-1)return null;
		late[4]=A[maxmark];
		timesheet.remove(maxmark);
		maxmark=findmax(timesheet);
		if(maxmark==-1)return null;
		late[5]=A[maxmark];
		timesheet.remove(maxmark);
		
		
		minmark=findminutemin(timesheets);
		if(minmark==-1)return null;
		early[2]=A[minmark];
		timesheets.remove(minmark);
		minmark=findmin(timesheets);
		if(minmark==-1)return null;
		early[3]=A[minmark];
		timesheets.remove(minmark);
		minmark=findminutemin(timesheets);
		if(minmark==-1)return null;
		early[4]=A[minmark];
		timesheets.remove(minmark);
		minmark=findmin(timesheets);
		if(minmark==-1)return null;
		early[5]=A[minmark];
		timesheets.remove(minmark);
		
		
		
		return late;
	}
	
	public static int findhour_1(HashMap<Integer,Integer> time){
		int maxhour=-1;
		int key=-1;
		for(int i=0;i<6;i++){
			if(time.containsKey(i)){
				int a=time.get(i);
				if(a<3 && maxhour<a){
					maxhour=a;
					key=i;
				}
			}
		}
		
		
		return key;
	}
	
	public static int findhour_2(HashMap<Integer,Integer> time){
		int minhour=3;
		int key=-1;
		for(int i=0;i<6;i++){
			if(time.containsKey(i)){
				int a=time.get(i);
				if( minhour>a){
					minhour=a;
					key=i;
				}
			}
		}
		
		
		return key;
	}
	
	
	public static int findmax(HashMap<Integer,Integer> time){
		 int max =0;
		 int key =-1;
		 for(int i=0;i<6;i++){
			 if(time.containsKey(i)){
				 int a=time.get(i);
				 if(max<a){
					 max=a;
					 key=i;
				 }
			 }
		 }
		 return key;
	}
	
	public static int findmin(HashMap<Integer,Integer> time){
		 int min =10;
		 int key =-1;
		 for(int i=0;i<6;i++){
			 if(time.containsKey(i)){
				 int a=time.get(i);
				 if(min>a){
					 min=a;
					 key=i;
				 }
			 }
		 }
		 return key;
	}
	
	public static int findsamllmax(HashMap<Integer,Integer> time){
		 int max =0;
		 int key =-1;
		 for(int i=0;i<6;i++){
			 if(time.containsKey(i)){
				 int a=time.get(i);
				 if(max<a && a<4){
					 max=a;
					 key=i;
				 }
			 }
		 }
		 return key;
	}
	
	public static int findsamllmin(HashMap<Integer,Integer> time){
		 int min =4;
		 int key =-1;
		 for(int i=0;i<6;i++){
			 if(time.containsKey(i)){
				 int a=time.get(i);
				 if(min>a){
					 min=a;
					 key=i;
				 }
			 }
		 }
		 return key;
	}
	
	public static int findminutemax(HashMap<Integer,Integer> time){
		 int max =0;
		 int key =-1;
		 for(int i=0;i<6;i++){
			 if(time.containsKey(i)){
				 int a=time.get(i);
				 if(max<a && a<6){
					 max=a;
					 key=i;
				 }
			 }
		 }
		 return key;
	}
	
	public static int findminutemin(HashMap<Integer,Integer> time){
		 int min =6;
		 int key =-1;
		 for(int i=0;i<6;i++){
			 if(time.containsKey(i)){
				 int a=time.get(i);
				 if(min>a){
					 min=a;
					 key=i;
				 }
			 }
		 }
		 return key;
	}
	
	
	public static void main(String[] args) throws IOException {
		int[] A={1,2,2,3,4,1};
		int[] a=Findtime.findthetime(A);
		
		System.out.println(a[0]);
		System.out.println(a[1]);
		System.out.println(a[2]);
		System.out.println(a[3]);
		System.out.println(a[4]);
		System.out.println(a[5]);
	}
	
	
	
}
