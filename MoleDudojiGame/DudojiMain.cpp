#include<SFML/Graphics.hpp>
#define WIDTH 544
#define HEIGHT 340
//(���� ���߱�) �δ��� ����

using namespace sf;
using namespace std;

int main(void) {
	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture t1;
    t1.loadFromFile("images/background.jpg");

    Sprite s1;
    s1.setTexture(t1);

    

    //x������ ����Ǵ� �ڵ�
    // �����찡 �����ִ� ������ ���α׷��� ��� ����.
    while (app.isOpen())
    {
        // ������ �ݺ��Ǵ� ���� Ʈ���Ű� �ɸ� �������� �̺�Ʈ üũ
        Event event;
        while (app.pollEvent(event))
        {
            //"close ��û" �̺�Ʈ. �����츦 ����.
            if (event.type == Event::Closed)
                app.close();
        }
        app.clear();
        app.draw(s1);
        app.display();
    }

    return 0;
}