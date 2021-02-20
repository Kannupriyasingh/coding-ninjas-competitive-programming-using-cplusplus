/*
In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.
Input Format:
First line will have a single integer ‘n’, denoting the number of students in the class.
Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.
Output Format:
Print ‘n’ lines having two values: First, the position of student in the class and second his name.
Constraints:
1 <= n <= 10^5
0 <= m1, m2, m3 <= 100
Sample Input:
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99
Sample Output:
1 Shubham
2 Mohit
3 Rishabh

*/



/*#include<bits/stdc++.h>
using namespace std;

struct data
{
    string name;
    int no;
};

bool compare(data a, data b)
{
	return a.no > b.no;
}

int main()
{
    int n;
    cin>>n;
    
	data *student = new data[n];
    for(int i=0;i<n;i++)
    {
        cin>>student[i].name;
        int x,y,z;
        cin>>x>>y>>z;
        student[i].no=x+y+z;
    }
    
    stable_sort(student,student+n,compare);
    
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<student[i].name<<endl;
    }
    
    
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct student{
    public:
    string name;
    int totalnumber;
};

bool compare(student s1, student s2)
{
         return s1.totalnumber > s2.totalnumber;
}
int main()
{
    int n;
    cin >> n;
    student a[n];
   for(int i = 0; i < n; i++)
   {
       cin >> a[i].name ;
       int m1, m2, m3;
       cin >> m1 >> m2 >> m3;
       a[i].totalnumber = m1 + m2 + m3;
   }
    stable_sort(a, a + n, compare);
    
    for(int i = 0; i < n; i++)
        cout << i + 1 << " " << a[i].name << endl;
    
    return 0;
}
    
    
