#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int arr[101];
int check[101][50][2];
int n, m;

int search(int idx, int section, int p)
{
   if (idx == n && section == m)
      return 0;
   if (idx == n)
      return -987654321;

   if (check[idx][section][p] !=-1)
      return check[idx][section][p];

   if (p == 0)
   {
      check[idx][section][p] = search(idx + 1, section + 1, 1) + arr[idx];
      int temp = search(idx + 1, section, 0);

      if (check[idx][section][p] < temp)
         check[idx][section][p] = temp;
   }

   else
   {
      check[idx][section][p] = search(idx + 1, section, 1) + arr[idx];
      int temp = search(idx + 1, section, 0);

      if (check[idx][section][p] < temp)
         check[idx][section][p] = temp;
   }

   return check[idx][section][p];
}


int main()
{
   memset(check, -1, sizeof(check));

   cin >> n >> m;
   for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);

   cout << search(0, 0, 0) << endl;
}