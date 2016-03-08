/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) 
{
	int len1 = 0, len2 = 0, i;
	for (i = 0; dob1[i] != '\0'; i++)
	{
		len1++;
	}
	if (len1 > 10)
	{
		return -1;
	}
	for (i = 0; dob2[i] != '\0'; i++)
	{
		len2++;
	}
	if (len2 > 10)
	{
		return -1;
	}

	if (!(dob1[0] >= 48 && dob1[0] <= 57 && dob1[1] >= 48 && dob1[1] <= 57 && dob1[3] >= 48 && dob1[3] <= 57 && dob1[4] >= 48 && dob1[4] <= 57 && dob1[6] >= 48 && dob1[6] <= 57 && dob1[7] >= 48 && dob1[7] <= 57 && dob1[8] >= 48 && dob1[8] <= 57 && dob1[9] >= 48 && dob1[9] <= 57))
	{
		return -1;
	}
	if (!(dob2[0] >= 48 && dob2[0] <= 57 && dob2[1] >= 48 && dob2[1] <= 57 && dob2[3] >= 48 && dob2[3] <= 57 && dob2[4] >= 48 && dob2[4] <= 57 && dob2[6] >= 48 && dob2[6] <= 57 && dob2[7] >= 48 && dob2[7] <= 57 && dob2[8] >= 48 && dob2[8] <= 57 && dob2[9] >= 48 && dob2[9] <= 57))
	{
		return -1;
	}

	int y1 = (dob1[6] - 48) * 1000 + (dob1[7] - 48) * 100 + (dob1[8] - 48) * 10 + (dob1[9] - 48);
	int y2 = (dob2[6] - 48) * 1000 + (dob2[7] - 48) * 100 + (dob2[8] - 48) * 10 + (dob2[9] - 48);
	int m1 = (dob1[3] - 48) * 10 + (dob1[4] - 48);
	int m2 = (dob2[3] - 48) * 10 + (dob2[4] - 48);
	int d1 = (dob1[0] - 48) * 10 + (dob1[1] - 48);
	int d2 = (dob2[0] - 48) * 10 + (dob2[1] - 48);

	if (!(m2 >= 1 && m2 <= 12 && m1 >= 1 && m1 <= 12))
	{
		return -1;
	}
	else if (m2 >= 1 && m2 <= 12 && m1 >= 1 && m1 <= 12)
	{
		if (m1 % 2 == 0 && m1 != 2 && !(d1 >= 1 && d1 <= 30))
		{
			return -1;
		}
		if (m2 % 2 == 0 && m2 != 2 && !(d2 >= 1 && d2 <= 30))
		{
			return -1;
		}
		if (m1 == 2 && y1 % 4 == 0 && !(d1 >= 1 && d1 <= 29))
		{
			return -1;
		}
		if (m2 == 2 && y2 % 4 == 0 && !(d2 >= 1 && d2 <= 29))
		{
			return -1;
		}
		if (m1 == 2 && y1 % 4 != 0 && !(d1 >= 1 && d1 <= 28))
		{
			return -1;
		}
		if (m2 == 2 && y2 % 4 != 0 && !(d2 >= 1 && d2 <= 28))
		{
			return -1;
		}
		if (m1 % 2 != 0 && !(d1 >= 1 && d1 <= 31))
		{
			return -1;
		}
		if (m2 % 2 != 0 && !(d2 >= 1 && d2 <= 31))
		{
			return -1;
		}
	}

	if (y1 > y2 && y1 > 0 && y2 > 0)
	{
		return 2;
	}
	else if (y2 > y1 && y1 > 0 && y2 > 0)
	{
		return 1;
	}
	else if (y1 == y2)
	{
		if (m1 > m2)
		{
			return 2;
		}
		else if (m2 > m1)
		{
			return 1;
		}
		else if (m1 == m2)
		{
			if (d1 > d2)
			{
				return 2;
			}
			else if (d2 > d1)
			{
				return 1;
			}
			else if (d1 == d2)
			{
				return 0;
			}
		}
	}

	return -1;
}
