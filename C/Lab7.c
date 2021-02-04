#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
_Bool yaochu(char a) {
	return (a == '1' || a == '9' || a == '0') ? true : false;
}
int unique(char arr[][2], int n) {
	int i, j, count = 0;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (arr[j][0] == arr[i][0] && arr[j][1] == arr[i][1]) count++;
	return count;
}
void swap(char *a, char *b) {
	char temp=*a;
	*a=*b;
	*b=temp;
}
void sort(char arr[][2], int n) {
	int i, j, np = 0, ns = 0, nm = 0, nw = 0, nd = 0,ny,n0;
	for (i = 0; i < n; i++)
		if (arr[i][1] == 'p') np++;
		else if (arr[i][1] == 's') ns++;
		else if (arr[i][1] == 'm') nm++;
		else if (arr[i][0] == '0') {
			if (arr[i][1] == 'e' || arr[i][1] == 'x' || arr[i][1] == 'w' || arr[i][1] == 'n') nw++;
			else nd++;
		}
	ny = np + ns + nm, n0 = nw + nd;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (arr[j][0] >= '1'&&arr[j][0] <= '9'&&arr[i][0] == '0') { swap(&arr[i][0], &arr[j][0]); swap(&arr[i][1], &arr[j][1]); }
	for (i = 0; i < ny - 1; i++)
		for (j = i + 1; j < ny; j++)
			if ((arr[j][1] == 'p'&&arr[i][1] == 's') || (arr[j][1] == 's'&&arr[i][1] == 'm') || (arr[j][1] == 'p'&&arr[i][1] == 'm')) { swap(&arr[i][0], &arr[j][0]); swap(&arr[i][1], &arr[j][1]); }
	for (i = 0; i < np - 1; i++)
		for (j = i + 1; j < np; j++)
			if (arr[j][0] < arr[i][0]) { swap(&arr[i][0], &arr[j][0]); swap(&arr[i][1], &arr[j][1]); }
	for (i = np; i < np + ns - 1; i++)
		for (j = i + 1; j < np + ns; j++)
			if (arr[j][0] < arr[i][0]) { swap(&arr[i][0], &arr[j][0]); swap(&arr[i][1], &arr[j][1]); }
	for (i = np + ns; i < ny - 1; i++)
		for (j = i + 1; j < ny; j++)
			if (arr[j][0] < arr[i][0]) { swap(&arr[i][0], &arr[j][0]); swap(&arr[i][1], &arr[j][1]); }
	for (i = ny; i < ny + n0 - 1; i++)
		for (j = i + 1; j < ny + n0; j++)
			if ((arr[j][1] == 'e' || arr[j][1] == 'x' || arr[j][1] == 'w' || arr[j][1] == 'n') && (arr[i][1] == 'z' || arr[i][1] == 'b' || arr[i][1] == 'f')) { swap(&arr[i][0], &arr[j][0]); swap(&arr[i][1], &arr[j][1]); }
	for (i = ny; i < ny + nw - 1; i++)
		for (j = i + 1; j < ny + nw; j++)
			if (((arr[j][1] == 'x' || arr[j][1] == 'w' || arr[j][1] == 'n') && arr[i][1] == 'e') || ((arr[j][1] == 'w' || arr[j][1] == 'n') && arr[i][1] == 'x') || (arr[j][1] == 'n'&&arr[i][1] == 'w')) { swap(&arr[i][0], &arr[j][0]); swap(&arr[i][1], &arr[j][1]); }
	for (i = ny + nw; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (((arr[j][1] == 'b' || arr[j][1] == 'f') && arr[i][1] == 'z') || (arr[j][1] == 'f'&&arr[i][1] == 'b')) { swap(&arr[i][0], &arr[j][0]); swap(&arr[i][1], &arr[j][1]); }
}
_Bool kokushimusou(char ht[][2], int nht, int nmh) {
	int i = 0; _Bool ret[2];
	if (nmh == 0 && unique(ht, nht) != 0)
		for (i = 0; i < nht; i++)
			if (yaochu(ht[i][0])) {
				ret[0] = true;
				if (unique(ht, nht) == 1) ret[1] = true;
				else ret[1] = false;
			}
			else { ret[0] = false; break; }
	return *ret;
}
int Honor_mentsu(char tri[2][4],int ntri,char kan[2][3],int nkan,char dw,char pw){
	int i,fan=0;
	for (i = 0; i < ntri; i++) {
		if (tri[0][i] == '0' && (tri[1][i] == 'z' || tri[1][i] == 'b' || tri[1][i] == 'f')) {
			if (tri[1][i] == dw || tri[1][i] == pw) { i += 3; return 2; }
			else { i+=3;fan=1;}
		}
	}
	for (i = 0; i < nkan; i++) {
		if (kan[0][i] == '0' && fan == 0 && (kan[1][i] == 'z' || kan[1][i] == 'b' || kan[1][i] == 'f')) {
			if (kan[1][i] == dw || kan[1][i] == pw) { i += 3; return 2; }
			else { i += 3; fan = 1; }
		}
	}
	return fan;
}
int Common_hand(char lt[2], char seq[2][4], int nseq, char pair[2],char dw,char pw,char ht[][2],int nht,int nloto) {
	if (nseq == 4 && pair[1] != pw && pair[1] != dw&&nloto==0) {
		for (int i = 1; i < nseq; i++) {
			if ((seq[0][i] == lt[0] && seq[1][i] == lt[1]) || (seq[0][i] + 2 == lt[0] && seq[1][i] + 2 == lt[1])) return 1;
		}
	}
	return 0;
}
int Peko(int ntri, int npair, int nht, char ht[][2],int nmh,int nseq) {
	if (nmh == 0 && unique(ht, nht) - ntri - npair == 3) return 1;
	else if (unique(ht, nht) == 7 && nmh == 0 && nseq == 4 && npair == 1) return 3;
	else return 0;
}
int jtc(char tri[2][4], int ntri, char pair[2]) {
	int i, ndt=0;
	for (i = 0; i < ntri; i++) {
		if (tri[0][i] == '0' && (tri[1][i] == 'z' || tri[1][i] == 'b' || tri[1][i] == 'f')) ndt++;
	}
	if (pair[0] == '0' && (pair[1] == 'z' || pair[1] == 'b' || pair[1] == 'f') && ndt == 2) return 2;
	else return 0;
}
int Sanshukuto(char seq[2][4],int nseq,char tri[2][4],int ntri,int nmh) {
	if (nseq == 3 && seq[0][0] == seq[0][1] && seq[0][0] == seq[0][2] && seq[1][0] == 'p'&&seq[1][1] == 's'&&seq[1][2] == 'm') { return (nmh == 0) ? 2 : 1; }
	if (ntri == 3&&tri[0][0] == tri[0][1] && tri[0][0] == tri[0][2] && tri[1][0] == 'p'&&tri[1][1] == 's'&&tri[1][2] == 'm') return 2;
	return 0;
}
int one_suit(char ht[][2], int nht,int nmh) {
	int i, nss=0;
	for (int i = 1; i < nht; i++)
		if (ht[i][0] == ht[i - 1][0] && ht[i][1] == ht[i - 1][1]){
			if (ht[i][0] != '0') nss++; 
		}
		else return 0;
	if (nht - nss > 1 && nht - nss < 5) return (nmh == 0) ? 3 : 2;
	else if (nss == 0)return (nmh == 0) ? 6 : 5;
}
int Sanankou(char meihai[4][2][3],int nmh,int ce[3]) {
	int i,t = 0;
	for (i = 0; i < nmh; i++) {
		if (meihai[0][0][i] == meihai[1][0][i] || meihai[0][1][i] == meihai[1][1][i]||ce[i]==0) t++;
	}
	return (nmh == t) ? 2 : 0;
}
int Dola(int redd,char indd[10][2],int nindd,char ht[][2],int nht,char kan[2][4],int nkan) {
	int i, j, ret = 0;
	for (i = 0; i < nindd; i++) {
		if (indd[i][0]!='0') indd[i][0]++;
		else if (indd[i][1] == 'e') indd[i][1] = 'x';
		else if (indd[i][1] == 'x') indd[i][1] = 'w';
		else if (indd[i][1] == 'w') indd[i][1] = 'n';
		else if (indd[i][1] == 'n') indd[i][1] = 'e';
		if (indd[i][1] == 'b') indd[i][1] = 'f';
		else if (indd[i][1] == 'f') indd[i][1] = 'z';
		else if (indd[i][1] == 'z') indd[i][1] = 'b';
		if (indd[i][0] == ':') indd[i][0] = '1';
	}
	for (i = 0; i < nindd; i++) {
		for (j = 0; j < nht; j++)
			if (ht[j][0] == indd[i][0] && ht[j][1] == indd[i][1]) ret++;
		for (j = 0; i < nkan; i++)
			if (kan[j][0] == indd[i][0] && kan[j][1] == indd[i][1]) ret++;
	}
	return ret + redd;
}
_Bool jfh(char tri[2][4],int ntri,char pair[2]) {
	if (pair[0] != '0' || ntri != 3) return false;
	for (int i = 0; i < 3; i++)
		if (tri[0][i] != '0') return false;
	if (tri[1][0] + tri[1][1] + tri[1][2] + pair[1] == 'e' + 'x' + 'w' + 'n') return true;
}
_Bool Lyuiso(char ht[][2], int nht) {
	for (int i=0;i<nht;i++)
		if ((ht[i][1]!='s'||(ht[i][0] != '2'&&ht[i][0]!='3'&&ht[i][0]!='4'&&ht[i][0]!='6'&&ht[i][0]!='8'))&&(ht[i][0]!='0'||ht[i][1]!='f')) return 0;
	return 1;
}
int Chulenpouton(char oht[][2],int nht,int nmh) {
	char ht[13][2]; int i, j;
	for (i = 0; i < nht; i++) {
		for (j = 0; j < i; j++) {
			ht[j][0] = oht[j][0]; ht[j][1] = oht[j][1];
		}
		for (j = i; j < nht; j++) {
			ht[j][0] = oht[j + 1][0]; ht[j][1] = oht[j + 1][1];
		}
		if (ht[0][0] == '1'&&ht[1][0] == '1'&&ht[2][0] == '1'&&ht[3][0] == '2'&&ht[4][0] == '3'&&ht[5][0] == '4'&&ht[6][0] == '5'&&ht[7][0] == '6'&&ht[8][0] == '7'&&ht[9][0] == '8'&&ht[10][0] == '9'&&ht[11][0] == '9'&&ht[12][0] == '9'&&nmh == 0) return (nht == 13) ? 2 : 1;
	}
	return 0;
}
int fmen(char tri[2][4],int ntri,char kan[2][4],int nkan,char lt[2], int ltf) {
	for (int i=0;i<ntri;i++)
		if (tri[0][i] == lt[0] && tri[1][i] == lt[1]) {
			if (ltf == 0) return (yaochu(lt[0])) ? 4 : 2;
			else return (yaochu(lt[0])) ? 8 : 4;
		}
	for (int i = 0; i < nkan; i++)
		if (kan[0][i] == lt[0] && kan[1][i] == lt[1]) {
			if (ltf == 0) return (yaochu(lt[0])) ? 16 : 8;
			else return (yaochu(lt[0])) ? 32 : 16;
		}
}
int main() {
	int nht,lichi,ltf,dwi,pwi,ipatsu,redd,i,j,nmh,point,fan=0,fu=20,ce[3],nindd,wint,nseq=0,ntri=0,npair=0,nkan=0,nhon=0,nloto=0,yak=0,win=0,a=0,mhlen=0,mhl[3]={0};
	char ht[18][2], meihai[4][2][3], indd[10][2],strh[43],stri[31],tri[2][4],seq[2][4],pair[2],kan[2][4],lt[2],dw='0',pw='0',strm[12],str1[12],str2[12];
	//FILE *fpi = fopen("input_1.txt", 'w+');
	//FILE *fpo = fopen("output.txt", 'w+');
	scanf("%d%d%d%d%d%d%d%d", &nht, &lichi, &ltf, &dwi, &pwi, &ipatsu, &wint, &redd);
	scanf("%s", strh);
	for (i = 0; i < nht; i++) {
		ht[i][0] = strh[3 * i]; ht[i][1] = strh[3 * i + 1];
	}
	scanf("%d", &nmh);
	for (i = 0; i < nmh; i++) {
		scanf("%d", &ce[i]);
		scanf("%s", strm);
		if (i == 0) strcpy(str1, strm);
		if (i == 1) strcpy(str2, strm);
		for (j = 0; j < 4; j++) {
			meihai[j][0][i] = strm[3 * i]; meihai[j][1][i] = strm[3 * i + 1];
		}
		mhl[i] = (meihai[4][0][i] != '\0') ? 4 : 3;
		mhlen += mhl[i];
	}
	lt[0] = ht[nht - mhlen - 1][0]; lt[1] = ht[nht - mhlen - 1][1];
	if (mhl[0] == 3) {
		for (i = nht - mhlen; i < mhl[0] + nht - mhlen; i++) {
			ht[i][0] = str1[3 * (i - nht + mhlen)]; ht[i][1] = str1[3 * (i - nht + mhlen) + 1];
		}
	}
	if (mhl[1] == 3) {
		for (i = mhl[0] + nht - mhlen; i < mhl[0] + mhl[1] + nht - mhlen; i++) {
			ht[i][0] = str2[3 * (i - mhl[0] - nht + mhlen)]; ht[i][1] = str2[3 * (i - mhl[0] - nht + mhlen) + 1];
		}
	}
	if (mhl[2] == 3) {
		for (i = mhl[0] + mhl[1] + nht - mhlen; i < nht; i++) {
			ht[i][0] = strm[3 * (i - mhl[0] - mhl[1] - nht + mhlen)]; ht[i][1] = strm[3 * (i - mhl[0] - mhl[1] - nht + mhlen) + 1];
		}
	}
	sort(ht, nht);
	scanf("%s", stri); nindd = (strlen(stri)) / 3;
	for (i = 0; i < nindd; i++) {
		indd[i][0] = stri[3 * i]; indd[i][1] = stri[3 * i - 1];
	}
	for (int i = 0; i < nmh; i++) {
		if (meihai[0][0][i] == meihai[1][0][i] && meihai[0][1][i] == meihai[1][1][i]) {
			if (meihai[3][0][i] == meihai[2][0][i]) { kan[0][nkan] = meihai[0][0][i]; kan[1][nkan] = meihai[0][1][i]; nkan++; }
			else { tri[0][ntri] = meihai[0][0][i]; tri[1][ntri] = meihai[0][1][i]; ntri++; }
		}
		else { seq[0][nseq] = meihai[0][0][i]; seq[1][nseq] = meihai[0][1][i]; nseq++; }
	}
	i = 2;
	while (i <= nht-mhlen && npair < 2) {
		if ((ht[i][1] == ht[i - 1][1] && ht[i][1] == ht[i - 2][1]) && (ht[i][0] == ht[i - 1][0] - 1 && ht[i][0] == ht[i - 2][0] - 2)) { seq[0][nseq] = ht[i][0]; seq[1][nseq] = ht[i][1]; i += 3; nseq++; }
		else if ((ht[i][1] == ht[i - 1][1] && ht[i][1] == ht[i - 2][1]) && (ht[i][0] == ht[i - 1][0] + 1 && ht[i][0] == ht[i - 2][0] + 2)) { seq[0][nseq] = ht[i - 2][0]; seq[1][nseq] = ht[i - 2][1]; i += 3; nseq++; }
		if (ht[i - 1][1] == ht[i - 2][1] && ht[i - 1][0] == ht[i - 2][0]) {
			if (i > nht-mhlen) break;
			else if (ht[i][1] == ht[i - 2][1] && ht[i][0] == ht[i - 2][0]) { tri[0][ntri] = ht[i - 2][0]; tri[1][ntri] = ht[i - 2][1]; i += 3; ntri++; }
			else { pair[0] = ht[i - 1][0]; pair[1] = ht[i - 1][1]; i += 2; npair++; }
		}
	}
	if ((nseq + ntri + nkan == 4 && npair == 1) || kokushimusou(ht, nht, nmh) || unique(ht, nht) == 7) win=1;
	for (i = 1; i < nht; i++) {
		if (ht[i][0] == '0') nhon++;
		else if (ht[i][0] == '1' || ht[i][0] == '9') nloto++;
	}
	if (dwi == 1) dw = 'e';
	if (dwi == 2) dw = 'x';
	if (dwi == 3) dw = 'w';
	if (dwi == 4) dw = 'n';
	if (pwi == 1) pw = 'e';
	if (pwi == 2) pw = 'x';
	if (pwi == 3) pw = 'w';
	if (pwi == 4) pw = 'n';
	if (win) {
		if (nmh == 0 && ltf == 1) fan += 1;//Menzen tsumo
		fan += Honor_mentsu(tri, ntri, kan, nkan, dw, pw);
		fan += lichi;
		if (nhon + nloto == 0) fan += 1;//Danyao
		fan += Common_hand(lt, seq, nseq, pair, dw, pw, ht, nht, nloto);
		fan += ipatsu;
		fan += Peko(ntri, npair, nht, ht, nmh, nseq);
		if (ltf != 0) fan += 1;//Chakan,Linshankaihou,Hoteilaoyui,Haiteilaoyu
		if (ntri == 3 && tri[1][0] == tri[1][1] == tri[1][2] && tri[0][0] == '1'&&tri[0][1] == '4'&&tri[0][2] == '7') fan += (nmh == 0) ? 2 : 1;//Ikitsukan
		fan += jtc(tri, ntri, pair);
		fan += Sanshukuto(seq, nseq, tri, ntri, nmh);
		fan += Sanankou(meihai,nmh,ce);
		fan += (nkan == 3) ? 2 : 0;//Sankantsu
		if (nloto == nht) fan += (nmh == 0) ? 3 : 2;//Zenobiyao
		if (nhon >= 1 && nseq >= 1) fan+= (nmh == 0) ? 2 : 1;//Chunzenobiyao
		if (nhon + nloto == nht && nhon >= 1 && nloto >= 1) fan += 2;//Honloto
		if (ntri + nkan == 4) fan += 2;//Toitoi
		if (unique(ht, nht) == 7) fan + 2;//Seven pairs
		fan += one_suit(ht, nht, nmh);
		fan += Dola(redd, indd, nindd, ht, nht, kan, nkan);
		if (wint) yak++;//Natural win,Earthly hand,Person hand
		yak += jfh(tri, ntri, pair);
		if (nkan == 4) yak++;//Sikantsu
		if (ntri + nkan == 4 && (lt[0] != pair[0] || lt[1] != pair[1]) && ltf == 1) yak++;//Siankou
		if (nloto == nht) yak++;//Chinloutou
		if (nhon == nht) yak++;//Tsuiso
		yak += Lyuiso(ht, nht);
		if (tri[0][0] == '0'&&tri[0][1] == '0'&&tri[0][2] == '0'&&tri[1][0] == 'b'&&tri[1][1] == 'f'&&tri[1][2] == 'z'&&ntri == 3) yak++;//Grand three chiefs
		yak += Chulenpouton(ht, nht,nmh);
		if (tri[0][0] == '0'&&tri[0][1] == '0'&&tri[0][2] == '0'&&tri[0][3] == '0'&&tri[1][0] == 'e'&&tri[1][1] == 'x'&&tri[1][2] == 'w'&&tri[1][2] == 'n'&&ntri == 4) yak += 2;//Grand four happiness
		if (ntri + nkan == 4 && lt[0] == pair[0] && lt[1] == pair[1]) yak += 2;//Siankoudanji
		if (nmh == 0 &&( ltf == 0|| ltf == 3|| ltf == 5)) fu += 10;
		if (ltf == 1|| ltf == 2|| ltf == 4) fu += 2;
		if (lt[0] == pair[0] && lt[1] == pair[1]) fu += 2;
		for (i = 0; i < nseq; i++) {
			if (seq[0][i] + 1 == lt[0] && seq[1][i] == lt[1]) { fu += 2; break; }
			else if ((seq[0][i] == '1'&&lt[0] == '3') || (seq[0][i] == '7'&&lt[0] == '7') && seq[1][i] == lt[1]) { fu += 2; break; }
		}
		if (pair[0] == '0' && (pair[1] == 'z' || pair[1] == 'b' || pair[1] == 'f')) fu += 2;
		if (pair[0] == '0'&&pair[1] == pw) fu += 2;
		if (pair[0] == '0'&&pair[1] == dw) fu += 2;
		fu += fmen(tri, ntri, kan, nkan, lt, ltf);
		if (unique(ht, nht) == 7 || kokushimusou(ht, nht, nmh)) fu = 25;
		if (Common_hand(lt, seq, nseq, pair, dw, pw, ht, nht, nloto)) fu = (ltf == 1 || ltf == 2 || ltf == 4) ? 20 : 30;
		if (fu % 10 != 0) fu += 10 - fu % 10;
	}
	if (fan > 0 && fan < 5) a = fu * pow(2, fan + 2);
	if (fan == 5) a = 2000;
	if (fan >= 6 && fan <= 7) a = 3000;
	if (fan >= 8 && fan <= 10) a = 4000;
	if (fan >= 11 && fan <= 12) a = 6000;
	if (fan >= 13) a = fan / 13 * 8000;
	yak += fan / 13;
	if (yak > 0) a = 8000 * yak;
	point = (pw == dw) ? a * 6 : a * 4;
	printf("%d",point);
	//fclose(fpi); 
	//fclose(fpo);
	system("pause");
	return 0;
}