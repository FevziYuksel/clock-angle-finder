
#include "clock.h"


double calculation(const char* str)
{
	char h_str[2], m_str[2];
	int hour = 0, min = 0;

	if (str == NULL)
	{
		printf("Arguments are empty\n");
		return -1;
	}

	if (strlen(str) != 5 || str[2] != ':')
	{
		printf("Format must be HH:MM\n");
		return -1;
	}

	if (!isdigit(str[0]) || !isdigit(str[1]) || !isdigit(str[3]) || !isdigit(str[4]))
	{
		printf("Values must be number\n");
		return -1;
	}


	h_str[0] = str[0];
	h_str[1] = str[1];
	m_str[0] = str[3];
	m_str[1] = str[4];

	hour = atoi(h_str);
	min = atoi(m_str);


	if (hour > 23 || hour < 0)
	{
		printf("Hour must 0 to 23\n");
		return -1;
	}

	if (min > 59 || min < 0)
	{
		printf("Minute must be 0 to 59\n");
		return -1;
	}

	if (hour > 12 || hour == 0)
		return (double)abs((hour %= 12) * 60 - min * 11) / 2;



	return  (double)abs(hour * 60 - min * 11) / 2;
}

