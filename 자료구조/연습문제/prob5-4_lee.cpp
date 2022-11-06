//테스트를 모두 통과하였습니다.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define Len 100

int main() {
	char line[Len];
	int i = 0;
	int len = 0;
	FILE* fp = fopen("sample.html", "r");
	char saved_file[] = "sample.txt";
	FILE* fp2 = fopen(saved_file, "w");

	while (!feof(fp))
	{
		while (fgets(line, Len, fp) != NULL)
		{
			len = strlen(line);
			i = 0;
			for (i; i < len; i++)
			{
				if (line[i] == '<') 
				{
					for (i = i + 1; i < len; i++) 
					{
						if (line[i] == '>') 
						{
							break;
						}
					}
				}

				else
				{
					if (fp2 != NULL)
					{
						fprintf(fp2, "%c", line[i]);
					}
				}
			}
		}
	}
	fclose(fp2);
	fclose(fp);
	return 0;
}