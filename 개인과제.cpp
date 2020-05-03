#include <stdio.h>
#include <bangtal.h>


SceneID scene1,scene2,scene3,scene4;
ObjectID start,start1,title,help,end,player,hint1,hint2,hint3,hint4,goal,table,up,down,left,right;

int playerx = 780, playery = 70;
int i = 6, j = 6;
int mazetable[7][7]{
	{2,1,0,0,0,4,1},
	{0,0,0,1,1,0,0},
	{1,1,0,1,0,1,0},
	{0,0,0,1,0,0,0},
	{1,0,1,0,0,0,1},
	{0,0,0,0,1,0,0},
	{3,0,1,0,1,0,0}
};


ObjectID located(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);

	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}
	return object;
}



void resetplayer() {
	i = 6;
	j = 6;
	playerx = 780;
	playery = 70;
	locateObject(player, scene2, playerx, playery);
	showMessage("틀렸습니다");
}

void all() {
	showObject(up);
	showObject(down);
	showObject(right);
	showObject(left);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == start) {
		enterScene(scene2);
	} 
	else if (object == help) {
		enterScene(scene3);
	}
	else if (object == start1) {
		enterScene(scene1);
	}
	else if (object == end) {
		endGame();
	}
	else if (object == hint3) {
		if (i == 0 || mazetable[i - 1][j] == 1) {
			hideObject(up);
		}
		if (i == 6 || mazetable[i + 1][j] == 1) {
			hideObject(down);
		}
		if (j == 6 || mazetable[i][j + 1] == 1) {
			hideObject(right);
		}
		if (j == 0 || mazetable[i][j - 1] == 1) {
			hideObject(left);
		}
		hideObject(hint3);
	}
	else if (object == hint4) {
		if (i == 0 || mazetable[i - 1][j] == 1) {
			hideObject(up);
		}
		if (i == 6 || mazetable[i + 1][j] == 1) {
			hideObject(down);
		}
		if (j == 6 || mazetable[i][j + 1] == 1) {
			hideObject(right);
		}
		if (j == 0 || mazetable[i][j - 1] == 1) {
			hideObject(left);
		}
		hideObject(hint4);
	}
	else if (object == up) {
		if (i > 0 && mazetable[i-1][j] == 0) {
			i -= 1;
			playery += 80;
			locateObject(player, scene2, playerx, playery);
			all();
		}
		else if (i > 0 && mazetable[i - 1][j] == 1) {
			resetplayer();
			all();
		}
		else if (i > 0 && mazetable[i - 1][j] == 2) {
			enterScene(scene4);
		}
		else if (i > 0 && mazetable[i - 1][j] == 3) {
			i -= 1;
			playery += 80;
			locateObject(player, scene2, playerx, playery);
			all();
			hideObject(hint1);
			showObject(hint3);
		}
		else if (i > 0 && mazetable[i - 1][j] == 4) {
			i -= 1;
			playery += 80;
			locateObject(player, scene2, playerx, playery);
			all();
			hideObject(hint2);
			showObject(hint4);
		}
	}
	else if (object == down) {
		if (i <6  && mazetable[i + 1][j] == 0) {
			i += 1;
			playery -= 80;
			locateObject(player, scene2, playerx, playery);
			all();
		}
		else if (i < 6 && mazetable[i + 1][j] == 1) {
			resetplayer();
			all();
		}
		else if (i < 6 && mazetable[i + 1][j] == 2) {
			enterScene(scene4);
		}
		else if (i < 6 && mazetable[i + 1][j] == 3) {
			i += 1;
			playery -= 80;
			locateObject(player, scene2, playerx, playery);
			all();
			hideObject(hint1);
			showObject(hint3);
		}
		else if (i < 6 && mazetable[i + 1][j] == 4) {
			i += 1;
			playery -= 80;
			locateObject(player, scene2, playerx, playery);
			all();
			hideObject(hint2);
			showObject(hint4);
		}
	}
	else if (object == right) {
		if (j < 6 && mazetable[i][j+1] == 0) {
			j += 1;
			playerx += 80;
			locateObject(player, scene2, playerx, playery);
			all();
		}
		else if (j < 6 && mazetable[i][j + 1] == 1) {
			resetplayer();
			all();
		}
		else if (j < 6 && mazetable[i][j + 1] == 2) {
			enterScene(scene4);
		}
		else if (j < 6 && mazetable[i][j + 1] == 3) {
			j += 1;
			playerx += 80;
			locateObject(player, scene2, playerx, playery);
			all();
			hideObject(hint1);
			showObject(hint3);
		}
		else if (j < 6 && mazetable[i][j + 1] == 4) {
			j += 1;
			playerx += 80;
			locateObject(player, scene2, playerx, playery);
			all();
			hideObject(hint2);
			showObject(hint4);
		}
	}
	else if (object == left) {
		if (j > 0 && mazetable[i][j - 1] == 0) {
			j -= 1;
			playerx -= 80;
			locateObject(player, scene2, playerx, playery);
			all();
		}
		else if (j > 0 && mazetable[i][j - 1] == 1) {
			resetplayer();
			all();
		}
		else if (j > 0 && mazetable[i][j - 1] == 2) {
			enterScene(scene4);
		}
		else if (j > 0 && mazetable[i][j - 1] == 3) {
			j -= 1;
			playerx -= 80;
			locateObject(player, scene2, playerx, playery);
			all();
			hideObject(hint1);
			showObject(hint3);
		}
		else if (j > 0 && mazetable[i][j - 1] == 4) {
			j -= 1;
			playerx -= 80;
			locateObject(player, scene2, playerx, playery);
			all();
			hideObject(hint2);
			showObject(hint4);
		}
	}
}



int main() {
	setMouseCallback(mouseCallback);
	
	scene1 = createScene("memory maze","black.png");
	scene2 = createScene("기억의 미로", "white.png");
	scene3 = createScene("도움말", "helpscene.png");
	scene4 = createScene("clear", "scene4.png");


	start = located("start.png", scene1, 520, 200, true);
	start1 = located("home.png", scene3, 520, 50, true);
	end = located("end.png", scene4, 520, 150, true);
	title = located("title.png", scene1, 300, 400, true);
	help = located("help.png", scene1, 520, 120, true);
	table = located("table.png", scene2, 280, 50, true);
	player = located("player.png", scene2, playerx, playery, true);
	hint1 = located("hint.png", scene2, 330, 80, true);
	hint2 = located("hint.png", scene2, 730, 560, true);
	hint3 = located("hint.png", scene2, 50, 440, false);
	hint4 = located("hint.png", scene2, 100, 440, false);
	goal = located("goal.png", scene2, 335, 555, true);
	up = located("up.png", scene2, 1080, 420, true);
	down = located("down.png", scene2, 1080, 200, true);
	right = located("right.png", scene2, 1180, 310, true);
	left = located("left.png", scene2, 980, 310, true);

	startGame(scene1);
}