#include <stdio.h>

int bCnt; //Bracket count
int pCnt; //Parenthesis count
int qCnt; //Quotes count
int brCnt; //Braces count
//int lineCnt; //Line count

int main(int argc,char* argv[]) {
	//lineCnt = 0;

	bCnt = 0;
	pCnt = 0;
	qCnt = 0;
	brCnt = 0;

	FILE *fileHdl = fopen(argv[1],"r");
	
	char c, cPrev;
	cPrev = fgetc(fileHdl);
	//printf("%c",cPrev);
	c = fgetc(fileHdl);

	while(c != EOF) {
		//printf("%c",c);
		
		if((c=='/') && (cPrev=='/')) {
			do{c = fgetc(fileHdl);}while(c != '\n');
		}
		
		switch(c) {
			case '{': bCnt++; break;
			case '}': bCnt--; break;
			case '(': pCnt++; break;
			case ')': pCnt--; break;
			case '"': qCnt++; break;
			case '[': brCnt++; break;
			case ']': brCnt--; break;
		}
		cPrev = c;
		c = fgetc(fileHdl);
	}
	
	fclose(fileHdl);
	
	//printf("%d\n %d\n %d\n %d\n", bCnt, pCnt, qCnt, brCnt);
	
	if(bCnt != 0) {
		printf("Unbalanced brackets detected in this code...");
	}
	if(pCnt != 0) {
		printf("Unbalanced parenthesis detected in this code...");
	}
	if(qCnt%2 != 0) {
		printf("Unbalanced quotation marks detected in this code...");
	}
	if(brCnt != 0) {
		printf("Unbalanced brackets detected in this code...");
	}
	            
	printf("\n+++++++++++++++++++++++\n| ANALYSIS TERMINATED |\n+++++++++++++++++++++++\n");
	
	return 0;
}
