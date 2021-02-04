#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
void swap(int *a, int *b)
{
	int temp; temp = *a; *a = *b; *b = temp;
}
int score(int sets[6][6], int last, int bao, int richi, int z, int zf, int cf, int yifa, int door, int tdr)
{
	int fan = 0, fu = 0, a = 0, a2 = 1, ph = 0, fan1 = 0, fan2 = 0, w, w1, w2, w3, t;
	int ss[6][6] = { 0 };
	int bd[10] = { 0 };
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			ss[i][j] = sets[i][j];
	for (int i = 1; i < 6; i++)
	{
		if (ss[i][0] == 1 && i != 1)
		{
			for (int j = 0; j < 6; j++)
				swap(&ss[1][j], &ss[i][j]);
			break;
		}
	}
	for (int i = 1; i < 4; i++)
		for (int j = 2; j < 6 - i; j++)
			if (ss[j][1] > ss[j + 1][1])
			{
				for (int k = 0; k < 6; k++)
					swap(&ss[j][k], &ss[j + 1][k]);
			}
	if (door == 0 && (z == 1 || z == 2 || z == 4)) fan1++;/*Menzen tsumo(门清自摸)*/
	for (int i = 2; i < 6; i++)/*Honor mentsu(役牌)*/
	{
		if (ss[i][0] >= 3 && ss[i][1] >= 32) fan1++;
		if (ss[i][0] >= 3 && ss[i][1] == zf) fan1++;
		if (ss[i][0] >= 3 && ss[i][1] == cf) fan1++;
	}
	fan1 += richi;/*Lichi,W Lichi(立直，w立直)*/
	w = 0;/*Danyao(断幺)*/
	for (int i = 1; i < 6; i++)
	{
		if (ss[i][0] < 3) t = ss[i][0] + 1;
		else t = ss[i][0];
		for (int j = 1; j <= t; j++)
			if (ss[i][j] > 27 || ss[i][j] % 9 <= 1) w = 1;
	}
	if (w == 0) fan1++;
	if (ss[1][1] != zf && ss[1][1] != cf && ss[1][1] <= 31) ph = 1;/*Common hand(平和)*/
	if (ph == 1)
		for (int i = 2; i < 6; i++)
			if (ss[i][0] != 2) { ph = 0; break; }
	if (ph == 1)
	{
		ph = 0;
		for (int i = 2; i < 6; i++)
			if ((ss[i][1] == last && ss[i][3] % 9 != 0) || (ss[i][3] == last && ss[i][1] % 9 != 1)) { ph = 1; break; }
	}
	if (ph == 1 && door == 0) fan1++;
	fan1 += yifa;/*Ipatsu(一发)*/
	if (door == 0)/*Ipeko(一杯口)*/
	{
		for (int i = 2; i < 5; i++)
		{
			if (ss[i][0] == 2 && ss[i + 1][0] == 2)
			{
				w = 0;
				for (int j=1;j<=3;j++)
					if (ss[i][j] != ss[i + 1][j]) { w = 1; break; }
				if (w == 0) { fan1++; break; }
			}
		}
	}
	if (z > 1) fan1++;/*Linshankaihou,Hoteilaoyui,Haiteilaoyu,Chakan(岭上开花，河底摸鱼，海底捞月，抢杠)*/
	w1 = 0; w2 = 0;
	for (int i = 2; i < 4; i++)/*Ikitsukan(一气通贯)*/
	{
		if (ss[i][0] == 2 && ss[i][1] % 9 == 1)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (ss[j][0] == 2 && ss[j][1] == ss[i][1] + 3) w1 = 1;
				if (ss[j][0] == 2 && ss[j][1] == ss[i][1] + 6) w2 = 1;
			}
		}
	}
	if (w1 == 1 && w2 == 1) fan1 += 2 - door;
	w = 0;/*Junior three chiefs(小三元)*/
	for (int i = 2; i < 6; i++)
	{
		if (ss[i][1] >= 32) w++;
	}
	if (w > 1 && ss[1][1] >= 32) fan1 += 2;
	for (int i = 2; i < 4; i++)/*Sanshukutojun(三色同顺)*/
	{
		if (ss[i][0] == 2 && ss[i][1] < 8)
		{
			w1 = 0;
			w2 = 0;
			for (int j = i + 1; j < 6; j++)
			{
				if (ss[j][0] == 2 && ss[j][1] == ss[i][1] + 9) w1 = 1;
				if (ss[j][0] == 2 && ss[j][1] == ss[i][1] + 18) w2 = 1;
			}
			if (w1 == 1 && w2 == 1) { fan1 += 2 - door; break; }
		}
	}
	for (int i = 2; i < 4; i++)/*Sanshukutoko(三色同刻)*/
	{
		if (ss[i][0] >= 3 && ss[i][1] <= 9)
		{
			w1 = 0;
			w2 = 0;
			for (int j = i + 1; j < 6; j++)
			{
				if (ss[j][0] >= 3 && ss[j][1] == ss[i][1] + 9) w1 = 1;
				if (ss[j][0] >= 3 && ss[j][1] == ss[i][1] + 18) w2 = 1;
			}
			if (w1 == 1 && w2 == 1) { fan1 += 2; break; }
		}
	}
	w = 0; w1 = 0;/*Sanankou(三暗刻)*/
	if (ss[1][1] == last) w1 = 1;
	for (int i = 2; i < 6; i++)
	{
		if (ss[i][0] >= 3 && ss[i][5] == 0) w++;
		else if (ss[i][5] == 0 && ss[i][0] < 4)
		{
			if (ss[i][1] == last) w1 = 1;
			if (ss[i][2] == last) w1 = 1;
			if (ss[i][3] == last) w1 = 1;
		}
	}
	if (w1 == 0) w--;
	if (w == 3) fan1 += 2;
	w = 0;/*Sankantsu(三杠子)*/
	for (int i = 2; i < 6; i++)
	{
		if (ss[i][0] == 4) w++;
	}
	if (w == 3) fan1 += 2;
	w1 = 0; w2 = 0; w3 = 0;/*Zenobiyao(混全带幺九)*/
	for (int i = 1; i < 6; i++)
	{
		w = 0;
		if (ss[i][1] > 27) w2 = 1;
		else w1 = 1;
		if (ss[i][0] == 2) w3 = 1;
		if (ss[i][0] < 3) t = ss[i][0] + 1;
		else t = ss[i][0];
		for (int j = 1; j <= t; j++)
		{
			if (ss[i][j] > 27 || ss[i][j] % 9 <= 1) { w = 1; break; }
		}
		if (w == 0) break;
	}
	if (w == 1 && w1 == 1 && w2 == 1 && w3 == 1) fan1 += 2 - door;
	w1 = 0; w2 = 0;;/*Chunzenobiyao(纯全带幺九)*/
	for (int i = 1; i < 6; i++)
	{
		w = 0;
		if (ss[i][1] > 27) { w2 = 1; break; }
		else w1 = 1;
		if (ss[i][0] < 3) t = ss[i][0] + 1;
		else t = ss[i][0];
		for (int j = 1; j <= t; j++)
		{
			if (ss[i][j] <= 27 && ss[i][j] % 9 <= 1) { w = 1; break; }
		}
		if (w == 0) break;
	}
	if (w == 1 && w1 == 1 && w2 == 0) fan1 += 3 - door;
	w = 0;  w1 = 0; w2 = 0;;/*Honloto(混老头)*/
	for (int i = 1; i < 6; i++)
	{
		if (ss[i][1] > 27) w2 = 1;
		else w1 = 1;
		if (ss[i][0] == 2) { w = 1; break; }
		if (ss[i][1] <= 27 && ss[i][1] % 9 > 1) { w = 1; break; }
	}
	if (w == 0 && w1 == 1 && w2 == 1) fan1 += 2;
	w = 0;/*Toitoi(对对和)*/
	for (int i = 2; i < 6; i++)
	{
		if (ss[i][0] == 2) { w = 1; break; }
	}
	if (w == 0) fan1 += 2;
	if (door == 0)/*Apeko(二杯口)*/
	{
		if (ss[2][0] == 2 && ss[3][0] == 2 && ss[2][1] == ss[3][1] && ss[4][0] == 2 && ss[5][0] == 2 && ss[4][1] == ss[5][1]) fan1 += 2;
	}
	w1 = 0; w2 = 0; w = 0;/*Mixed one suit(混一色)*/
	for (int i = 1; i < 6; i++)
	{
		if (ss[i][1] > 27) w1 = 1;
		else w2 = 1;
		if (ss[i][1] <= 27)
		{
			if (w == 0) w = (ss[i][1] - 1) / 9 + 1;
			else if (w != (ss[i][1] - 1) / 9 + 1) { w = 0; break; }
		}
	}
	if (w != 0 && w1 == 1 && w2 == 1) fan1 += 3 - door;
	w1 = 0; w = 0;/*Pure one suit(清一色)*/
	for (int i = 1; i < 6; i++)
	{
		if (ss[i][1] > 27) { w1 = 1; break; }
		if (ss[i][1] <= 27)
		{
			if (w == 0) w = (ss[i][1] - 1) / 9 + 1;
			else if (w != (ss[i][1] - 1) / 9 + 1) { w = 0; break; }
		}
	}
	if (w != 0 && w1 == 0) fan1 += 6 - door;
	if (tdr == 1) fan2 += 13;/*Natural win,Earthly hand,Person hand(天和，地和，人和)*/
	w = 0;/*Junior four happiness(小四喜)*/
	for (int i = 2; i < 6; i++)
		if (ss[i][1] >= 28 && ss[i][1] <= 31) w++;
	if (w == 3 && ss[1][1] >= 28 && ss[1][1] <= 31) fan2 += 13;
	if (ss[2][0] == 4 && ss[3][0] == 4 && ss[4][0] == 4 && ss[5][0] == 4) fan2 += 13;/*Sikantsu(十八罗汉)*/
	if (ss[2][0] > 2 && ss[3][0] > 2 && ss[4][0] > 2 && ss[5][0] > 2 && ss[2][5] == 0 && ss[3][5] == 0 && ss[4][5] == 0 && ss[5][5] == 0)/*Siankou(四暗刻)*/
	{
		if (ss[1][1] == last) fan2 += 26;
		else if (z==1 || z==2 || z==4) fan2 += 13;
	}
	w = 0;/*Siankou(清老头)*/
	for (int i = 2; i < 6; i++)
	{
		if (ss[i][0] == 2) { w = 1; break; }
		if (ss[i][1] > 27 || ss[i][1] % 9 > 1) { w = 1; break; }
	}
	if (w == 0 && ss[1][1] <= 27 && ss[1][1] % 9 <= 1) fan2 += 13;
	w = 0;/*Lyuiso(绿一色)*/
	for (int i = 1; i < 6; i++)
	{
		if (ss[i][0] < 3) t = ss[i][0] + 1;
		else t = ss[i][0];
		for (int j = 1; j <= t; j++)
		{
			if (ss[i][j] <= 10 || ss[i][j] == 14 || ss[i][j] == 16 || (ss[i][j] >= 18 && ss[i][j] != 33)) { w = 1; break; }
		}
		if (w == 1) break;
	}
	if (w == 0) fan2 += 13;
	w1 = 0; w = 0;/*Chulenpouton(九莲宝灯)*/
	for (int i = 1; i < 6; i++)
	{
		if (ss[i][1] > 27 || ss[i][0] == 4) { w1 = 1; break; }
		if (ss[i][1] <= 27)
		{
			if (w == 0) w = (ss[i][1] - 1) / 9 + 1;
			else if (w != (ss[i][1] - 1) / 9 + 1) { w = 0; break; }
		}
	}
	if (w != 0 && w1 == 0)
	{
		for (int i = 1; i < 6; i++)
		{
			if (ss[i][0] < 3) t = ss[i][0] + 1;
			else t = ss[i][0];
			for (int j = 1; j <= t; j++)
				bd[(ss[i][j] - 1) % 9 + 1]++;
		}
		bd[1] -= 3; bd[9] -= 3;
		for (int i = 2; i <= 8; i++)
			bd[i]--;
		w2 = 0; w3 = 0;
		for (int i = 1; i <= 9; i++)
		{
			if (bd[i] == 0) w2++;
			else if (bd[i] == 1) w3++;
		}
		if (w2 == 8 && w3 == 1)
		{
			if (bd[(last - 1) % 9 + 1] == 1) fan2 += 26;
			else fan2 += 13;
		}
	}
	w = 0;/*Grand three chiefs(大三元)*/
	for (int i = 2; i < 6; i++)
		if (ss[i][1] >= 32) w++;
	if (w == 3) fan2 += 13;
	w = 0;/*Grand four happiness(大四喜)*/
	for (int i = 2; i < 6; i++)
		if (ss[i][1] >= 28 && ss[i][1] <= 31) w++;
	if (w == 4) fan2 += 26;
	if (ss[1][1] > 27 && ss[2][1] > 27 && ss[3][1] > 27 && ss[4][1] > 27 && ss[5][1] > 27) fan2 += 13;/*Tsuiso(字一色)*/
	if (fan1 > fan2) fan = fan1;
	else fan = fan2;
	if (fan < 1) return 0;
	fan += bao;/*Dola(宝牌)*/
	if (fan < 5)
	{
		fu = 20;
		if (door == 0 && (z == 0 || z == 3 || z == 5)) fu += 10;
		if (z == 1 || z == 2 || z == 4) fu += 2;
		w = 0;
		if (ss[1][1] == last) fu += 2;
		else
		{
			for (int i = 2; i <= 5; i++)
			{
				if (ss[i][0] == 2 && ss[i][2] == last) { fu += 2; w = 1;  break; }
				if (ss[i][0] == 2 && ((ss[i][1] == last && ss[i][3] % 9 == 0) || (ss[i][3] == last && ss[i][1] % 9 == 1))) { fu += 2; w = 1;  break; }
			}
		}
		if (ss[1][1] == zf) fu += 2;
		if (ss[1][1] == cf) fu += 2;
		if (ss[1][1] >= 32 && ss[1][1] <= 34) fu += 2;
		for (int i = 2; i <= 5; i++)
		{
			if (ss[i][0] == 3)
			{
				if (ss[i][1] < 27 && ss[i][1] % 9>1)
				{
					if (ss[i][5] == 0 && (w == 1 || ss[i][1] != last)) fu += 4;
					else fu += 2;
				}
				else
				{
					if (ss[i][5] == 0 && (w == 1 || ss[i][1] != last)) fu += 8;
					else fu += 4;
				}
			}
			else if (ss[i][0] == 4)
			{
				if (ss[i][1] < 27 && ss[i][1] % 9>1)
				{
					if (ss[i][5] == 0 && (w == 1 || ss[i][1] != last)) fu += 16;
					else fu += 8;
				}
				else
				{
					if (ss[i][5] == 0 && (w == 1 || ss[i][1] != last)) fu += 32;
					else fu += 16;
				}
			}
		}
		if (ph == 1)
		{
			if (door==0 && (z == 1 || z == 2 || z == 4)) fu = 20;
			else if (door == 1) fu = 30;
		}
		if (fu % 10 != 0) fu = (fu / 10 + 1) * 10;
		for (int i = 0; i < fan + 2; i++)
			a2 *= 2;
		a = fu * a2;
		if (a > 2000) a = 2000;
	}
	else
	{
		if (fan == 5) a = 2000;
		if (fan >= 6 && fan <= 7) a = 3000;
		if (fan >= 8 && fan <= 10) a = 4000;
		if (fan >= 11 && fan <= 12) a = 6000;
		if (fan >= 13) a = fan / 13 * 8000;
	}
	return a;
}
int work(int a[40], int pair, int set, int sets[6][6], int last, int bao, int richi, int z, int zf, int cf, int yifa, int door, int tdr)
{
	if (set == 0 && pair == 0)
	{
		return score(sets, last, bao, richi, z, zf, cf, yifa, door, tdr);
	}
	int sc = 0, k = 0, t = 0, w = 0;
	for (int i = 1; i <= 34; i++)
		if (a[i] != 0)
		{
			k = i;
			break;
		}
	t = 6 - set - pair;
	if (set > 0)
	{
		if (k <= 27 && (k - 1) % 9 <= 6 && a[k + 1] != 0 && a[k + 2] != 0)
		{
			--a[k]; --a[k + 1]; --a[k + 2];
			sets[t][0] = 2; sets[t][1] = k; sets[t][2] = k + 1; sets[t][3] = k + 2;
			w = work(a, pair, set - 1, sets, last, bao, richi, z, zf ,cf, yifa, door, tdr);
			if (w > sc) sc = w;
			++a[k]; ++a[k + 1]; ++a[k + 2];
			sets[t][0] = 0; sets[t][1] = 0; sets[t][2] = 0; sets[t][3] = 0;
		}
		if (a[k] >= 3)
		{
			a[k] -= 3;
			sets[t][0] = 3; sets[t][1] = k; sets[t][2] = k; sets[t][3] = k;
			w = work(a, pair, set - 1, sets, last, bao, richi, z, zf, cf, yifa, door, tdr);
			if (w > sc) sc = w;
			a[k] += 3;
			sets[t][0] = 0; sets[t][1] = 0; sets[t][2] = 0; sets[t][3] = 0;
		}
	}
	if (pair > 0)
	{
		if (a[k] >= 2)
		{
			a[k] -= 2;
			sets[t][0] = 1; sets[t][1] = k; sets[t][2] = k;
			w = work(a, pair - 1, set, sets, last, bao, richi, z, zf , cf, yifa, door, tdr);
			if (w > sc) sc = w;
			a[k] += 2;
			sets[t][0] = 0; sets[t][1] = 0; sets[t][2] = 0;
		}
	}
	return sc;
}
int main()
{
	int judge; char s[60] = { 0 }, b[40] = { 0 }; int a[40] = { 0 }; int a2[40] = { 0 }; int sets[6][6] = { 0 }; 
	int jt, t, e, richi, z, num, bao = 0, n, last, kan, set, sc = 0, mt, zf, cf, oya = 0, yifa, w7, sc1, fan, fan1, fan2, s2, tdr, door = 0, zi ,lt, wa, to, su, aka;
	scanf("%d %d %d %d %d %d %d %d\n", &num, &richi, &z, &zf, &cf, &yifa, &tdr, &aka);
	if (zf == 1) oya = 1;
	zf += 27;
	cf += 27;
	scanf("%s", s);
	kan = num - 14;
	set = 4 - kan;
	for (int i = 1; i <= strlen(s); i += 3)
	{
		if (s[i] == 'p') ++a[s[i - 1] - 48];
		if (s[i] == 's') ++a[s[i - 1] - 48 + 9];
		if (s[i] == 'm') ++a[s[i - 1] - 48 + 18];
		if (s[i] == 'e') ++a[28];
		if (s[i] == 'x') ++a[29];
		if (s[i] == 'w') ++a[30];
		if (s[i] == 'n') ++a[31];
		if (s[i] == 'b') ++a[32];
		if (s[i] == 'f') ++a[33];
		if (s[i] == 'z') ++a[34];
		if (i + 3 > strlen(s))
		{
			if (s[i] == 'p') last = s[i - 1] - 48;
			if (s[i] == 's') last = s[i - 1] - 48 + 9;
			if (s[i] == 'm') last = s[i - 1] - 48 + 18;
			if (s[i] == 'e') last = 28;
			if (s[i] == 'x') last = 29;
			if (s[i] == 'w') last = 30;
			if (s[i] == 'n') last = 31;
			if (s[i] == 'b') last = 32;
			if (s[i] == 'f') last = 33;
			if (s[i] == 'z') last = 34;
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d\n", &mt);
		scanf("%s", s);
		for (int j = 1; j < strlen(s); j += 3)
		{
			if (s[j] == 'p') { sets[i][j / 3 + 1] = s[j - 1] - 48; ++a2[s[j - 1] - 48]; }
			if (s[j] == 's') { sets[i][j / 3 + 1] = s[j - 1] - 48 + 9; ++a2[s[j - 1] - 48 + 9]; }
			if (s[j] == 'm') { sets[i][j / 3 + 1] = s[j - 1] - 48 + 18; ++a2[s[j - 1] - 48 + 18]; }
			if (s[j] == 'e') { sets[i][j / 3 + 1] = 28; ++a2[28]; }
			if (s[j] == 'x') { sets[i][j / 3 + 1] = 29; ++a2[29]; }
			if (s[j] == 'w') { sets[i][j / 3 + 1] = 30; ++a2[30]; }
			if (s[j] == 'n') { sets[i][j / 3 + 1] = 31; ++a2[31]; }
			if (s[j] == 'b') { sets[i][j / 3 + 1] = 32; ++a2[32]; }
			if (s[j] == 'f') { sets[i][j / 3 + 1] = 33; ++a2[33]; }
			if (s[j] == 'z') { sets[i][j / 3 + 1] = 34; ++a2[34]; }
			jt = j / 3 + 1;
		}
		sets[i][0] = jt;
		if (sets[i][1] != sets[i][2]) --sets[i][0];
		sets[i][5] = mt;
		if (jt == 3) set--;
		else if (jt == 4) kan--;
		if (mt == 1) door = 1;
	}
	scanf("%s", b);
	for (int i = 1; i < strlen(b); i += 3)
	{
		if (b[i] == 'p') bao += a[(b[i - 1] - 48) % 9 + 1] + a2[(b[i - 1] - 48) % 9 + 1];
		if (b[i] == 's') bao += a[(b[i - 1] - 48) % 9 + 10] + a2[(b[i - 1] - 48) % 9 + 10];
		if (b[i] == 'm') bao += a[(b[i - 1] - 48) % 9 + 19] + a2[(b[i - 1] - 48) % 9 + 19];
		if (b[i] == 'e') bao += a[29] + a2[29];
		if (b[i] == 'x') bao += a[30] + a2[30];
		if (b[i] == 'w') bao += a[31] + a2[31];
		if (b[i] == 'n') bao += a[28] + a2[28];
		if (b[i] == 'b') bao += a[33] + a2[33];
		if (b[i] == 'f') bao += a[34] + a2[34];
		if (b[i] == 'z') bao += a[32] + a2[32];
	}
	bao += aka;
	sc = work(a, 1, set, sets, last, bao, richi, z, zf, cf, yifa, door, tdr);
	w7 = 0;/*seven pairs(七对子)*/
	for (int i = 1; i <= 34; i++)
		if (a[i] != 2 && a[i] != 0)
		{
			w7 = 1;
			break;
		}
	fan = 0; fan1 = 0; fan2 = 0;
	if (w7 == 0 && door == 0 && num == 14)
	{
		fan1 = 2;
		fan1 += richi;
		if (z == 1 || z == 3 || z == 5) fan1++;
		if (z == 4) fan1 += 2;
		if (yifa == 1) fan1++;
		zi = a[28] + a[29] + a[30] + a[31] + a[32] + a[33] + a[34];
		lt = a[1] + a[9] + a[10] + a[18] + a[19] + a[27];
		to = a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9];
		su = a[10] + a[11] + a[12] + a[13] + a[14] + a[15] + a[16] + a[17] + a[18];
		wa = a[19] + a[20] + a[21] + a[22] + a[23] + a[24] + a[25] + a[26] + a[27];
		if (zi + lt == 0) fan1++;/*Danyao(断幺)*/
		if (zi + lt == 14 && lt % 14 != 0) fan1 += 3;/*Honloto(混老头)*/
		if (zi != 0 && (zi + to == 14 || zi + su == 14 || zi + wa == 14)) fan1 += 3;/*Mixed one suit(混一色)*/
		if (to == 14 || su == 14 || wa == 14) fan1 += 6;/*Pure one suit(清一色)*/
		if (tdr == 1) fan2 += 13;/*Natural win,Earthly hand,Person hand(天和，地和，人和)*/
		if (a[11] + a[12] + a[13] + a[15] + a[17] + a[33] == 14) fan2 += 13;/*Lyuiso(绿一色)*/
		if (zi == 14) fan2 += 13; /*Tsuiso(字一色)*/
		if (lt == 14) fan2 += 13; /*Chinloutou(清老头)*/
		if (fan1 > fan2) fan = fan1; 
		else fan = fan2;
		if (fan > 0) fan += bao;
		if (fan < 5)
		{
			s2 = 1;
			for (int i = 0; i < fan + 2; i++)
				s2 *= 2;
			sc1 = 25 * s2;
		}
		else
		{
			if (fan == 5) sc1 = 2000;
			if (fan >= 6 && fan <= 7) sc1 = 3000;
			if (fan >= 8 && fan <= 10) sc1 = 4000;
			if (fan >= 11 && fan <= 12) sc1 = 6000;
			if (fan >= 13) sc1 = fan / 13 * 8000;
		}
		if (sc1 > sc) sc = sc1;
	}
	t = 0; e = 0;/*Kokushimusou(国士无双)*/
	if (a[1] == 1) t++; else if (a[1] == 2) e++;
	if (a[9] == 1) t++; else if (a[9] == 2) e++;
	if (a[10] == 1) t++; else if (a[10] == 2) e++;
	if (a[18] == 1) t++; else if (a[18] == 2) e++;
	if (a[19] == 1) t++; else if (a[19] == 2) e++;
	for (int i = 27; i <= 34; i++)
		if (a[i] == 1) t++; else if (a[i] == 2) e++;
	if (t == 12 && e == 1)
	{
		if (a[last] == 2) sc1 = 16000;
		else sc1 = 8000;
		if (tdr == 1) sc1 += 8000;
		if (sc1 > sc) sc = sc1;
	}
	if (oya == 1) sc = sc * 6;
	else sc = sc * 4;
	if (sc % 100 != 0) sc = (sc / 100 + 1) * 100;
	printf("%d\n", sc);
	system("PAUSE");
	return 0;
}