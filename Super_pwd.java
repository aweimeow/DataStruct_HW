import java.util.Random;
import java.io.*; 

public class Super_pwd {

	public static void main (String args[]) throws IOException
	{
		BufferedReader buf = new BufferedReader(
                new InputStreamReader(System.in)); 
		String yesorno = "";
		boolean restart = false;
		do{
			start();
			System.out.print("是否再來一次 ? (y/n) ：");
			yesorno = buf.readLine();
			if (yesorno.contains("y"))
			{
				for(int i = 0; i<10; i++)
					System.out.println();
				restart = true;
			}
			else {
				restart = false;
				System.out.println("遊戲結束。");
			}
		}while(restart == true);
	}
	public static void start() throws IOException 
	{
		int ans[]={1,2,3,4};
		int userans[]={0,0,0,0};
		int a=0 ,b=0;		//correct
		int times = 0;		//do times
		String text;
		int input;
		int tempgen = 0;
		BufferedReader buf = new BufferedReader(
                new InputStreamReader(System.in)); 
		boolean correct = true;
		boolean violate = false;
		boolean ans_repeat = false;
/////////////////////////////////////////////////////////
		System.out.println("產生亂數中 ...");
		for (int i =0; i<4; i ++)
		{
				tempgen = random();
				if(i==0)
				{
					ans[i] = tempgen;
				}
				else
				{
					do {
						for(int j =0; j<i; j++)
						{
							if(tempgen == ans[j])
							{
								ans_repeat = true;
								tempgen = random();
							}
							else
							{
								ans_repeat = false;
								ans[i] = tempgen;
							}
						}
					} while (ans_repeat == true);
				}
		}
		do {
			System.out.print("請輸入您的猜測：");
			text = buf.readLine();
			if(text.contains("ans"))
			{
				correct = false;
				//System.out.println("通關密語正確");
				System.out.print("Ans : ");
				for(int i = 0; i<4; i++)
				{
					System.out.print(ans[i]);
				}
				System.out.println();
			}
			else 
			{
				input = Integer.parseInt(text);
				for(int i = 0; i<4; i++)
				{
					if(i != 3)
						userans[i]=(int) (input/(Math.pow(10,(3-i))));
					else {
						userans[i]=input;
					}
					input -= userans[i]*(Math.pow(10,(3-i)));		
				}
				//////////////////check repeat///////////////////////////
				checkloop:
				for(int i=0; i<4; i++)
				{
					for(int j=0; j<4; j++)
					{
						if(i != j)
						{
							if(userans[i] == userans[j])
							{
								System.out.println("userans["+i+"]="+userans[i]+"; userans["+j+"]"+userans[j]);
								violate = true;
								correct = false;
								System.out.println("違反規則，請勿重覆輸入同樣數字。");
								break checkloop;
							}
						}
					}
				}
				/////////////////////////////////////////////////////////
				if(violate == false)
				{
					a=0; b=0;
					for(int i = 0; i<4; i++)
					{
						if (userans[i] != ans[i]) 
							correct = false;
						else
						{
							a +=1;
						}
						for(int j=0; j<4; j++)
						{
							if (i != j)
							{
								if (userans[i] == ans[j])
									b+=1;
							}
						}
						if(a==4)
							correct = true;
					}
					times +=1;
					System.out.println(a+"A"+b+"B"+"\t\t您已經猜了"+times+"次。");
				}		
			}
			
			violate = false;
			if(correct == true)
				System.out.println("恭喜你答對了 !");
		} while (correct == false);
		
	}
	public static int random(){
		int value =0 ;
		Random ran = new Random();
		value = ran.nextInt(10);
		return value;
	}
	
}
