#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>

using namespace std;

void display(int arr[3][3])
{
	cout<<endl;
	  for (int i =0 ; i<3; i++)
	  {
		for (int j = 0; j<3; j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << endl;
      }
};


int main ()
{
	srand(time(0));
	int arr[3][3]={{9,9,9},{0,0,0},{1,2,3}};
	display(arr);
	
	int piece;
	int chose;
	int com;
	
	
	
	
	cout << "which piece do you want to move"<<endl;
	cin  >> piece;
	 switch(piece){
	 	case 1:
	 		arr[1][0]= 1;
	 		arr[2][0]=0 ;
	 		
	 		 com = 1 + (rand() % 3);
	 		   switch(com){
	 		   	display(arr);
	 		   	case 1:
	 		       arr[1][0]= 9;
	 		       arr[0][1]=0 ;
	 		       
	 		        display(arr);   
	 		           cout << "which piece do you want to move"<<endl;
	 		           cin >> piece;
	 		            switch(piece){
	 		            	case 2:
	 		            		cout << "1 to move straight and 2 to kill"<<endl;
	 		            		cin >> chose;
	 		            		    switch (chose){
	 		            		    	case 1:
	 		            		    		arr[1][1]=2;
	 		            		    		arr [2][1]=0;
	 		            		    		arr [1][0]=0;
	 		            		    		arr [2][0]=9;
	 		            		    		display(arr);
	 		            		    		cout<< "computer won!!!";
	 		            		    		break;
	 		            		    	case 2:
	 		            		    		arr [1][1]=2;
	 		            		    		arr [2][1]=0;
	 		            		    		arr [0][2]=0;
	 		            		    		arr [1][2]=9;
	 		            		    		cout <<"you lose!!";
	 		            		    		break;
									 }
									break;
							case 3:
								arr [1][2]=3;
								arr [2][2]=0;
								arr [1][0]=0;
	 		            		arr [2][0]=9;
	 		            		display(arr);
	 		            		cout<< "computer won!!!";
								
								break;
						 }
	 		           
	 		           
	 		       break;
	 		    case 2:
	 		       arr[1][1]=9 ;
	 		       arr[0][1]= 0;
	 		           
	 		           display(arr);
	 		    		cout << "1 to kill and 2 to go straight"<< endl;
	 		    		cin >>piece;
	 		    		 switch(piece){
	 		    		 	case 1:
	 		    		 		arr[1][1]=3;
	 		    		 		arr[2][2]= 0;
	 		    		 		arr[1][1]=9;
	 		    		 		arr [0][2]=0;
	 		    		 		display(arr);
	 		    		 		cout << "you lose!!";
	 		    		 	break;
	 		    		 	case 2:
	 		    		 		arr[2][2]=0;
	 		    		 		arr[1][2]=3;
	 		    		 		display(arr);
	 		    		 		cout <<"congratulation you won!!!";
	 		    		 	 break;
						  }
	 		       break;
	 		    case 3:
	 		       arr[1][2]= 9;
	 		       arr[0][2]= 0;
	 		       
	 		           display(arr);
	 		           cout << "which piece you want to move"<<endl;
	 		           cin >> piece;
	 		             switch (piece){
						  case 1:
						  	arr [1][0]= 0;
						  	arr [0][1]=1;
						  	display(arr);
						  	cout<<endl<<"you won!!";
						  	break;
						  	
						  case 2:
							
	 		       		     cout << "1 to kill and 2 to go straight"<< endl;
	 		       	         cin >>chose;
	 		    		     switch(chose){
	 		    		 	case 1:
	 		    		 		arr[2][1]=0;
	 		    		 		arr [0][1]=0;
	 		    		 		arr [2][2]=9;
	 		    		 		display(arr);
	 		    		 		cout << "you lose!!!";
	 		    		 	break;
	 		    		 	case 2:
	 		    		 		arr[2][1]=0;
	 		    		 		arr[1][1]=2;
	 		    		 		display(arr);
	 		    		 		cout << "congratulation you won";
						   break;
						  }
	 		             break;
	 		            }
	 		      break;      
	           }
	 		break;
			
	 	case 2:
	 		arr[1][1]=2 ;
	 		arr[2][1]= 0;
	 		
	 		
	 		 com = 1 + (rand() % 4);
	 		   switch(com){
	 		   	case 1:
	 		       arr[1][0]= 9;
	 		       arr[0][0]=0 ;
	 		        
	 		        display(arr);
	 		        cout << "2 to kill and 3 to go straight"<<endl;
	 		        cin >> chose;
	 		        	switch(chose){
	 		        		case 2:
	 		        			arr[1][1]=0;
	 		        			arr[0][2]=2;
	 		        			display(arr);
	 		        			cout<<endl<< "you won!!!";
	 		        			break;
	 		        			
	 		        		case 3:
	 		        		arr[0][0]=0; arr[0][1]= 2;arr[0][2]=9 ;arr[1][0]= 9;arr[1][1]=0 ;arr[1][2]=9;arr[2][0]= 1;arr[2][1]= 0;arr[2][2]=0 ;
	 		        		display(arr);
	 		        		cout<<endl<< "you won!!";
	 		        		break;
	 		        		
						 }
					   
	 		       break;
	 		    case 2:
	 		       arr[1][1]=9 ;
	 		       arr[0][0]= 0;
	 		         
	 		         display(arr);
	 		         cout << "which piece you want to move"<<endl;
	 		         cin >> piece;
	 		           switch(piece){
	 		           	
	 		           	case 1:
	 		           	  cout << "1 to kill and 2 to go straight"<<endl;
	 		           	  cin >> chose;
	 		           	  switch (chose){
	 		    
	 		           	  	 
	 		           	  	 case 1:
	 		           	  	 	arr[1][1]=1;
	 		           	  	 	arr [2][0]=0;
	 		           	  	 	arr [0][2]=0;
								arr [1][2]=9;
								display(arr);
								cout << "you lose!!!";
								break;
								
							case 2:
							   arr [1][0]=1;
							   arr [2][0]=0;
							   arr [1][1]=0;
							   arr [2][1]=9;
							   display(arr);
							   cout << " computer won!!!";	 
							   break;		           	  	 
							  }
						break;
						
						case 3:
						  cout << "1 to kill and 2 to go straight"<<endl;
	 		           	  cin >> chose;
	 		           	  switch (chose){
	 		           	  	case 1:
	 		           	  		arr[1][1]=3;
	 		           	  		arr[2][2]=0;
	 		           	  		
	 		           	  		com = 1 + (rand()%2);
	 		           	  		switch (com){
									  
	 		           	  		   case 1:
	 		           	  		   	arr[0][0]=0; arr[0][1]=9 ;arr[0][2]=9 ;arr[1][0]=1 ;arr[1][1]=0 ;arr[1][2]=0 ;arr[2][0]=0 ;arr[2][1]=9 ;arr[2][2]=0 ;
	 		           	  		   	 display(arr);
	 		           	  		   	 cout << "you lose!!!";
	 		           	  		   	 break;
	 		           	  		 
	 		           	  		  case 2:
	 		           	  		  	arr[0][0]=0; arr[0][1]= 9;arr[0][2]=0;arr[1][0]=1 ;arr[1][1]= 3;arr[1][2]= 0;arr[2][0]= 0;arr[2][1]= 0;arr[2][2]=9 ;
	 		           	  		  	display(arr);
	 		           	  		   	 cout << "you lose!!!";
	 		           	  		   	 break;
							  }	
							  break;
							case 2:
								arr[0][0]=0; arr[0][1]= 9;arr[0][2]=9 ;arr[1][0]= 0;arr[1][1]= 0;arr[1][2]=3 ;arr[2][0]= 1;arr[2][1]= 9;arr[2][2]=0 ;
								display(arr);
	 		           	  		   	 cout << "you lose!!!";
	 		           	  		   	 break;
					     	}
					     break;	
						}
	 		       break;
	 		    case 3:
	 		       arr[1][1]= 9;
	 		       arr[0][2]= 0;
	 		       
	 		       display(arr);
	 		       cout << "which piece you want to move"<< endl;
	 		       cin>> piece;
	 		         switch(piece){
	 		         	case 1:
	 		         		cout<< " 1 to kill and 2 to go straight"<<endl;
	 		         		cin >> chose;
	 		         		  switch(chose){
	 		         		  	case 1:
	 		         		  		arr[2][0]= 0;
	 		         		  		arr [1][1]= 1;
	 		         		  		
	 		         		  		com = 1 + (rand()%2);
	 		         		  		  switch(com){
	 		         		  		  	case 1:
	 		         		  		  		arr[0][0]=0;
	 		         		  		  		arr[1][0]=9;
	 		         		  		  		
	 		         		  		  		display(arr);
	 		         		  		  		cout<< "1 to kill and 2 to go straight"<<endl;
	 		         		  		  		cin >> piece;
	 		         		  		  		cout << "dosen't matter you gonna lose";
	 		         		  		  		break;
	 		         		  		  	
	 		         		  		  	case 2:
	 		         		  		  		arr[0][0]=0;
	 		         		  		  		arr [1][1]=9;
	 		         		  		  		
	 		         		  		  		display(arr);
	 		         		  		  		cout << "1 to kill and 2 to go straight"<<endl;
	 		         		  		  		cin>>piece;
	 		         		  		  		  switch(piece){
	 		         		  		  		  	case 1:
	 		         		  		  		  		arr[2][2]=0;
	 		         		  		  		  		arr[1][1]=3;
	 		         		  		  		  		 
	 		         		  		  		  		 display(arr);
	 		         		  		  		  		 cout << endl <<"you won!!!";
	 		         		  		  		  		 break;
	 		         		  		  		  	
	 		         		  		  		  	case 2:
	 		         		  		  		  		arr[2][2]=0;
	 		         		  		  		  		arr[1][2]=3;
	 		         		  		  		  		arr [1][1]=0;
	 		         		  		  		  		arr [2][1]=9;
	 		         		  		  		  		 
	 		         		  		  		  		 display(arr);
	 		         		  		  		  		 cout <<endl<< "computer won!!!";
	 		         		  		  		  		 break;
													}
											break;
										  }
									break;
									
								case 2:
									arr[2][0]=0;
									arr[1][0]=1;
									arr[1][1]=0;
									arr[2][1]=9;
									
									display(arr);
									cout <<endl<<"you lose !!";
									break;
								}
							break;
							
					
						    	
						case 3:
							cout << "1 to kill and 2 to go straight"<< endl;
							cin >> chose;
							  switch(chose){
							  	case 1:
							  		arr[1][1]=3;
							  		arr[2][2]=0;
							  		arr [0][0]=0;
									arr [1][0]=9;
									
									display(arr);
									cout << endl<< "you lose!!";
									break;
									
								case 2:
									arr[1][2]=3;
									arr [2][2]=0;
									arr [1][1]=0;
									arr[2][1]=9;
									
									display(arr);
									cout <<endl<< "you lose !!!";
									break;
								 }
								 break;
					  }
	 		         
	 		       break;
	 		    case 4:
	 		       arr[1][2]=9 ;
	 		       arr[0][2]= 0;
	 		       
	 		       display(arr);
	 		       cout << "2 to kill and 1 to go straight"<<endl;
	 		       cin >> chose;
	 		       	switch(chose){
	 		       		case 2:
	 		       			arr[1][1]=0;
	 		       			arr [0][0]=2;
	 		       			display(arr);
	 		       			cout<< "you won!!";
	 		       			break;
	 		       			
	 		       		case 1:
	 		       			arr[0][0]=9; arr[0][1]=2 ;arr[0][2]= 0;arr[1][0]=9 ;arr[1][1]= 0;arr[1][2]=9 ;arr[2][0]= 0;arr[2][1]= 0;arr[2][2]=3 ;
	 		       			display(arr);
	 		       			cout<<endl<<"you won!!!";
	 		       			break;
						}
	 		       
	 		       
	 		       break;
	           }
	 		break;
	 	case 3:
	 		arr[1][2]= 3;
	 		arr[2][2]= 0;
	 		
	 		
	 		 com = 1 + (rand() % 3);
	 		   switch(com){
	 		   	case 1:
	 		       arr[1][2]= 9;
	 		       arr[0][1]=0 ;
	 		       
	 		       display(arr);
	 		       cout << endl<< "which piece do you want to move";
	 		       cin >> piece;
	 		       	  switch(piece){
	 		       	  	case 1:
	 		       	  		arr[0][0]=9; arr[0][1]= 0;arr[0][2]= 9;arr[1][0]= 1;arr[1][1]= 0;arr[1][2]= 0;arr[2][0]= 0;arr[2][1]=2 ;arr[2][2]= 9;
	 		       	  		display(arr);
	 		       	  		cout<<endl<<"you lose!!!";
	 		       	  		break;
	 		       	  		
	 		       	  	case 2:
	 		       	  		cout << "1 to kill and 2 to go straight"<<endl;
	 		       	  		cin>>chose;
	 		       	  			switch(chose){
	 		       	  				case 1:
	 		       	  					arr[0][0]=0; arr[0][1]=0 ;arr[0][2]= 9;arr[1][0]= 9;arr[1][1]= 0;arr[1][2]=2 ;arr[2][0]=1 ;arr[2][1]=0 ;arr[2][2]=0 ;
	 		       	  					display(arr);
	 		       	  					cout<<endl<< "you lose !!";
	 		       	  					break;
	 		       	  					
	 		       	  				case 2:
	 		       	  					arr[0][0]=9; arr[0][1]= 0;arr[0][2]=9 ;arr[1][0]=0 ;arr[1][1]=2 ;arr[1][2]=0 ;arr[2][0]= 0;arr[2][1]=0 ;arr[2][2]=3 ;
	 		       	  					display(arr);
	 		       	  					cout<< endl<< "computer won!!";
	 		       	  					break;
									  }
						   break;
						  }
	 		       
	 		       break;
	 		    case 2:
	 		       arr[1][1]=9 ;
	 		       arr[0][1]= 0;
	 		       
	 		       display(arr);
	 		       cout <<"1 to kil and 2 to go straight"<<endl;
	 		       cin >>piece;
	 		          switch(piece){
	 		          	case 1:
	 		          	   arr[0][0]=0; arr[0][1]=0 ;arr[0][2]= 9;arr[1][0]=0 ;arr[1][1]= 9;arr[1][2]= 3;arr[2][0]=0 ;arr[2][1]= 2;arr[2][2]=0 ;
	 		          	   display(arr);
	 		          	   cout<<endl<<"you lose!!!";
	 		          	   break;
	 		          	
	 		          	case 2:
	 		          		arr[2][0]=0;
	 		          		arr[1][0]=1;
	 		          		display(arr);
	 		          		cout<<endl<< "you won!!!";
	 		          		break;
	 		          		
					   }
	 		       
	 		       
	 		       break;
	 		    case 3:
	 		       arr[1][0]= 9;
	 		       arr[0][0]= 0;
	 		       
	 		    	display(arr);
	 		    	cout<< endl<< "which piece do you want to move"<<endl;
	 		    	cin >> piece;
	 		    		switch(piece){
	 		    			case 2:
	 		    				cout << "1 to kill and 2 to go straight "<<endl;
	 		    				cin >> chose;
	 		    					switch(chose){
	 		    						case 1:
	 		    							arr[0][0]=0; arr[0][1]=9 ;arr[0][2]=9 ;arr[1][0]=9 ;arr[1][1]=0 ;arr[1][2]=3 ;arr[2][0]=1 ;arr[2][1]= 0;arr[2][2]=0 ;
	 		    							display(arr);
	 		    							cout<<endl<< "you lose!!";
	 		    							break;
	 		    						case 2:
										 arr[0][0]=0; arr[0][1]=2 ;arr[0][2]=9 ;arr[1][0]=9 ;arr[1][1]=0 ;arr[1][2]=9 ;arr[2][0]= 1;arr[2][1]= 0;arr[2][2]=0 ;
										 display(arr);
										 cout<<endl<< "congratulation you won!!!";
										 break;	
									 }
							break;
							
							case 3:
								arr[0][1]=3;
								arr[1][2]=0;
								display(arr);
								cout<<endl<<"conragradulation you won!!";
							break;
						 }
	 		       break;
	           }
	 		break;
	 }
	
		cout<<endl;	   	
	display(arr);
	
	
	
	
    
	
	
}
	
	
