import java.util.*;
class FDAccount{ 
	double amount; 
	int noOfDays; 
	int ageofAcHolder; 
	public FDAccount(double b,int c,int d){ 
		amount = b; 
		noOfDays = c; 
		ageofAcHolder = d; 
	} 
	double interestgain = 0.0; 
	
	void calculateInterest(){ 
		if(amount<10000000){ 
			if(ageofAcHolder>=60){ 
				if(noOfDays>=7 && noOfDays<=14){ 
					interestgain = (amount*5.00)/100;
				} 
				else if(noOfDays>=15 && noOfDays<=29){ 
					interestgain = (amount*5.25)/100; 
				} else if(noOfDays>=30 && noOfDays<=45){ 
					interestgain = (amount*6.00)/100; 
				} else if(noOfDays>=45 && noOfDays<=60){ 
					interestgain = (amount*7.50)/100; 
				} else if(noOfDays>=61 && noOfDays<=184){ 
					interestgain = (amount*8.00)/100; 
				} else if(noOfDays>=185 && noOfDays<=365){ 
					interestgain = (amount*8.50)/100; 
				} System.out.println("Interestgain: "+interestgain); 
			} else{ if(noOfDays>=7 && noOfDays<=14){ 
				interestgain = (amount*4.50)/100; } 
				else if(noOfDays>=15 && noOfDays<=29){ 
					interestgain = (amount*4.75)/100; 
				} else if(noOfDays>=30 && noOfDays<=45){ 
					interestgain = (amount*5.50)/100; 
				} else if(noOfDays>=45 && noOfDays<=60){ 
					interestgain = (amount*7.00)/100; 
				} else if(noOfDays>=61 && noOfDays<=184){ 
					interestgain = (amount*7.50)/100; 
				} else if(noOfDays>=185 && noOfDays<=365){ 
					interestgain = (amount*8.00)/100; 
				} System.out.println("Interestgain: "+interestgain); 
			} 
		} 
		else{ 
			if(noOfDays>=7 && noOfDays<=14){ 
				interestgain = (amount*6.50)/100; 
			} else if(noOfDays>=15 && noOfDays<=29){ 
				interestgain = (amount*6.75)/100; 
			} else if(noOfDays>=30 && noOfDays<=45){ 
				interestgain = (amount*6.75)/100; 
			} else if(noOfDays>=45 && noOfDays<=60){ 
				interestgain = (amount*8.00)/100; 
			} else if(noOfDays>=61 && noOfDays<=184){ 
				interestgain = (amount*8.50)/100; 
			}else if(noOfDays>=185 && noOfDays<=365){ 
				interestgain = (amount*10.00)/100; 
			} System.out.println("Interestgain: "+interestgain); 
		} 
	} 
} 

class RDAccount{ 
	double amount; 
	int noOfmonths; 
	int ageofAcHolder; 
	public RDAccount(double a,int b,int c){ 
		amount = a; 
		noOfmonths = b; 
		ageofAcHolder = c; 
	} 
	double interestgain=0.0;
	void calculateInterest(){ 
		if(ageofAcHolder>=65){ 
			if(noOfmonths>=6 && noOfmonths<9){ 
				interestgain = (amount*8.00)/100; 
			} else if(noOfmonths>=9 && noOfmonths<12){ 
				interestgain = (amount*8.25)/100; 
			} else if(noOfmonths>=12 && noOfmonths<15){ 
				interestgain = (amount*8.50)/100; 
			} else if(noOfmonths>=15 && noOfmonths<18){ 
				interestgain = (amount*8.75)/100; 
			} else if(noOfmonths>=18 && noOfmonths<21){ 
				interestgain = (amount*9.00)/100; 
			} else if(noOfmonths>=21 && noOfmonths<=24){ 
				interestgain = (amount*9.25)/100; 
			} System.out.println("Interestgain "+ interestgain); 
		} else{ if(noOfmonths>=6 && noOfmonths<9){ 
			interestgain = (amount*7.50)/100; 
		} else if(noOfmonths>=9 && noOfmonths<12){ 
			interestgain = (amount*7.75)/100; 
		} else if(noOfmonths>=12 && noOfmonths<15){ 
			interestgain = (amount*8.00)/100; 
		} else if(noOfmonths>=15 && noOfmonths<18){ 
			interestgain = (amount*8.25)/100; 
		} else if(noOfmonths>=18 && noOfmonths<21){ 
			interestgain = (amount*8.50)/100;
		} else if(noOfmonths>=21 && noOfmonths<=24){ 
			interestgain = (amount*8.75)/100; 
		} System.out.println("Interestgain "+ interestgain); 
	} 
} 
} 

class SBaccount{ 
	double amount;
	String accountType; 
	public SBaccount(double a,String b){ 
		amount = a; accountType = b; 
	} double interestgain=0.0; 
	void calculateInterest(){ 
		if(accountType=="Normal"){ 
			interestgain = (amount*4)/100; 
		} else if(accountType=="NRI"){ 
			interestgain = (amount*6)/100; 
		} System.out.println("Interestgain "+interestgain); 
	}
} 
public class Main1 { 
	public static void main(String[] args) { 
		Scanner sc = new Scanner(System.in); // goto 
		System.out.println("1. Interest Calculator -FD"); 
		System.out.println("2. Interest Calculator -RD"); 
		System.out.println("3. Interest Calculator -SB"); 
		System.out.println("4. Exit"); 
		System.out.println("Enter your choice: "); 
		int a = sc.nextInt(); 
		if(a==1){ 
			System.out.println("Enter Amount "); 
			double amount = sc.nextDouble(); 
			System.out.println("Enter no of days "); 
			int days = sc.nextInt(); 
			System.out.println("Enter age of person "); 
			int age = sc.nextInt(); 
			FDAccount f = new FDAccount(amount,days,age); 
			f.calculateInterest(); // continue flag; 
		} else if(a==2){ 
			System.out.println("Enter Amount "); 
			double amount = sc.nextDouble(); 
			System.out.println("Enter no of months ");
			int months = sc.nextInt(); 
			System.out.println("Enter age of person "); 
			int age = sc.nextInt(); 
			RDAccount rd = new RDAccount(amount,months,age); 
			rd.calculateInterest(); // continue flag; 
		} else if(a==3){ 
			System.out.println("Enter Amount "); 
			double amount = sc.nextDouble(); 
			System.out.println("Enter type of account "); 
			String type = sc.next(); 
			SBaccount sb = new SBaccount(amount,type); 
			sb.calculateInterest(); // continue flag; 
		} else if(a==4){ 
			System.exit(0); 
		} 
	} 
}