
// rotate 90 deg clockwise
void rotate(char a[10][10])
{
  char t;
  for (int i=0; i< 5; i++)
    {
      for (int j=i; j<9-i; j++)
	{
	  t = a[i][j];
	  a[i][j] = a[9-j][i];
	  a[9-j][i] = a[9-i][9-j];
	  a[9-i][9-j] = a[j][9-i];
	  a[j][9-i] = t;
	}
    }
}
