#include<cstdio>
#include<iostream>
#include<sstream>
using namespace std;
int avai(int board[][8], int);
void clear(int board[][8]);
void fall(int board[][8], int, int, int);
int calc(int board[][8]);
int alg(int board[][8], int temp[][8]);
void AI(int board[][8]);
void serr(int board[][8]);
int main() {
	int board[8][8] = { 0 }, x, y, z;
	char temp;
	bool level;
	while (1) {
		string buffer;
		getline(cin, buffer);
		if (buffer.empty()) continue;
		istringstream ss(buffer);
		string command;
		ss >> command;
		if (command == "START") continue;
		if (command == "BEGIN") level = 0;
		if (command == "PLACE") {
			ss >> temp >> y >> z;
			x = temp - 'a';
			--y;
			board[y][x] = (z == 1) ? 1 : -1;
			continue;
		}
		if (command == "DONE") { cout << "OK" << endl; continue; }
		if (command == "TURN") {
			ss >> temp >> y;
			level = 1;
			x = temp - 'a';
			--y;
		}
		if (command == "PASS") level = 0;
		if (level == 0) {
			avai(board, -1);
			//serr(board);
			AI(board);
			clear(board);
			avai(board, 1);
			//serr(board);
		}
		if (level == 1) {
			fall(board, y, x, 1);
			clear(board);
			avai(board, -1);
			//serr(board);
			AI(board);
			clear(board);
			avai(board, 1);
			//serr(board);
		}
		if (command == "END") return 0;
	}
}
void serr(int board[][8]) {
	int r, c;
	cerr << "   ";
	for (c = 0; c < 8; c++) fprintf(stderr, "%c   ", c + 'a');
	for (r = 0; r < 8; r++) {
		cerr << endl << ' ';
		for (c = 0; c < 8; c++) {
			cerr << "+---";
			if (c == 7) cerr << "+\n";
		}
		fprintf(stderr, "%c", r + '1');
		for (c = 0; c < 8; c++) {
			if (board[r][c] == 1) cerr << "| X ";
			else if (board[r][c] == -1)	cerr << "| O ";
			else if (board[r][c] == 2) cerr << "| ` ";
			else cerr << "|   ";
			if (c == 7) cerr << "|";
		}
		if (r == 7) {
			cerr << endl << ' ';
			for (c = 0; c < 8; c++) {
				cerr << "+---";
				if (c == 7) cerr << "+\n";
			}
		}
	}
}
int avai(int board[][8], int p) {
	int dr, dc, r, c, x, y, pos = 0;
	for (r = 0; r < 8; r++) {
		for (c = 0; c < 8; c++) {
			if (board[r][c] == 1 || board[r][c] == -1) continue;
			for (dr = -1; dr <= 1; dr++) {
				for (dc = -1; dc <= 1; dc++) {
					if (r + dr < 0 || r + dr > 7 || c + dc < 0 || c + dc > 7 || (dr == 0 && dc == 0)) continue;
					if (board[r + dr][c + dc] == p) {
						x = r + dr; y = c + dc;
						while (1) {
							x += dr; y += dc;
							if (x < 0 || x > 7 || y < 0 || y > 7 || board[x][y] == 0 || board[x][y] == 2) break;
							if (board[x][y] == -p) {
								board[r][c] = 2;
								pos++;
								break;
							}
						}
					}
				}
			}
		}
	}
	return pos;
}
void clear(int board[][8]) {
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			if (board[r][c] == 2) board[r][c] = 0;
}
void fall(int board[][8], int r, int c, int p) {
	int dr = 0, dc = 0, x = 0, y = 0;
	board[r][c] = -p;
	for (dr = -1; dr <= 1; dr++) {
		for (dc = -1; dc <= 1; dc++) {
			if (r + dr < 0 || r + dr > 7 || c + dc < 0 || c + dc > 7 || (dr == 0 && dc == 0)) continue;
			if (board[r + dr][c + dc] == p) {
				x = r + dr; y = c + dc;
				while (1) {
					x += dr; y += dc;
					if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 0 || board[x][y] == 2) break;
					if (board[x][y] == -p) {
						while (board[x -= dr][y -= dc] == p) board[x][y] = -p;
						break;
					}
				}
			}
		}
	}
}
int calc(int board[][8]) {
	int s = 0, r, c;
	for (r = 0; r < 8; r++) {
		for (c = 0; c < 8; c++) {
			s = s - (board[r][c] == 1);
			s = s + (board[r][c] == -1);
		}
	}
	return s;
}
int alg(int board[][8], int temp[][8]) {
	int r, c, i, j, bup[8][8] = { 0 }, maxs = 0, s = 0;
	for (r = 0; r < 8; r++) {
		for (c = 0; c < 8; c++) {
			if (!temp[r][c]) continue;
			for (i = 0; i < 8; i++) {
				for (j = 0; j < 8; j++) {
					bup[i][j] = board[i][j];
				}
			}
			fall(bup, r, c, -1);
			s = calc(bup);
			if (maxs < s) maxs = s;
		}
	}
	return maxs;
}
void AI(int board[][8]) {
	int r, c, r1 = -1, c1 = -1, i, j, s, mins = 100, bup[8][8], tup[8][8];
	for (r = 0; r < 8; r++) {
		for (c = 0; c < 8; c++) {
			if (board[r][c] != 2) continue;
			for (i = 0; i < 8; i++) {
				for (j = 0; j < 8; j++) {
					bup[i][j] = board[i][j];
				}
			}
			fall(bup, r, c, -1);
			avai(bup, 1);
			s = alg(bup, tup);
			if (r == 0 || r == 7 || c == 0 || c == 7 || s < mins) {
				mins = s;
				r1 = r; c1 = c;
			}
		}
	}
	if (r1 != -1 && c1 != -1) {
		fall(board, r1, c1, -1);
		printf("%c %c\n", c1 + 'a', r1 + '1');
	}
	else if (avai(board, -1) == 0) cout << "PASS" << endl;
}