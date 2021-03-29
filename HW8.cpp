#include <iostream>
#include <algorithm>
using namespace std;

void sort(int *a[],int row,int col)
{
    int i,j,k,temp;

    for(i=0; i<row; i++)
    {
        for(k=0;k<col; k++)
        {
            for(j=0; j<col-k-1; j++)
            {
                if(a[i][j] > a[i][j+1])
                {
                    temp = a[i][j];
                    a[i][j] = a[i][j+1];
                    a[i][j+1] = temp;
                }
            }
        }
    }
}

int cmp(const void *a,const void *b)// this is for quick sort
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int num;
	
	cin >> num; //number of test data 
	cout << num << endl;
	//////////input//////////
	int n, i, j;
	for(i=0; i<=num; i++)
	{
		cout << "enter a value: ";
		cin >> n; // number of stacked wood
		int woodWH[n][2];//each wood has width and height
		for(i=0; i<n; i++)
		{
			cin >> woodWH[i][0] >> woodWH[i][1]; //given Width and Height
		}
		
		//////////sort by the area of each rectangle//////////
		//sort from the smallest one to the biggest//
		int *pa[n]; 
   	 	for(i=0; i<n; i++)
   	 	{
     		pa[i] = woodWH[i];
    	}

   		sort(pa,n,2);//sort by each row and column
   		
   		qsort(woodWH,n,sizeof(woodWH[0]),cmp); // quick sort algorithm
   			
   		for(i=0; i<n; i++)
    	{
       		for(j=0; j<2; j++)
        	{
           		cout << woodWH[i][j];
        	}
       	cout << endl;
    	}
    	
    	//////////compare each area of rectangle//////////	
		int temp = 1;//cuz it aleast 1 wood would be stacked
    	int sum = 0;
   	   	int area[n];
    	for(i=0; i<n; i++)	area[i] = woodWH[i][0] * woodWH[i][1];
    	
    	for(i=1; i<n; i++)
    	{
    		//the bigger one must be below
    		if(area[i] >= area[i-1]) temp++;
			//the smaller one is not necessarily on top
			if(woodWH[i][0] < woodWH[i-1][0] || woodWH[i][1] < woodWH[i-1][1]) temp--;
			if(temp >= 0) sum = temp;
			temp = 1;	
		} 
  
    		 
		//////////reset value//////////
		woodWH[n][2] = 0;
		pa[n] = 0;
	}
	cout << "end~" << endl;

}
