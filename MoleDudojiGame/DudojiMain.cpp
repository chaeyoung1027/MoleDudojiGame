#include<SFML/Graphics.hpp>
#define WIDTH 544
#define HEIGHT 340
//(문제 맞추기) 두더지 게임

using namespace sf;
using namespace std;

int main(void) {
	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture t1;
    t1.loadFromFile("images/background.jpg");

    Sprite s1;
    s1.setTexture(t1);

    

    //x누르면 종료되는 코드
    // 윈도우가 열려있는 동안은 프로그램을 계속 실행.
    while (app.isOpen())
    {
        // 루프가 반복되는 동안 트리거가 걸린 윈도우의 이벤트 체크
        Event event;
        while (app.pollEvent(event))
        {
            //"close 요청" 이벤트. 윈도우를 종료.
            if (event.type == Event::Closed)
                app.close();
        }
        app.clear();
        app.draw(s1);
        app.display();
    }

    return 0;
}