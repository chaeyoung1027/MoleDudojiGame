//(���� ���߱�) �δ��� ����
#include<SFML/Graphics.hpp>
#include<iostream>

#define WIDTH 1100
#define HEIGHT 942

using namespace sf;
using namespace std;

int main(void) {
    int x = 0, y = 0;

	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture background, hammer;
    background.loadFromFile("images/background.png");
    hammer.loadFromFile("images/�и�ġ.png");
    /*t1.loadFromFile("images/�δ���1.png");
    t1.loadFromFile("images/�δ���2.png");
    t1.loadFromFile("images/�δ���3.png");
    t1.loadFromFile("images/�δ���4.png");
    t1.loadFromFile("images/�δ���5.png");
    t1.loadFromFile("images/�δ���6.png");*/

    Sprite s1;
    s1.setTexture(background);

    //x������ ����Ǵ� �ڵ�
    //SFML ���� ���� - �����찡 ������ ���� �ݺ�
    while (app.isOpen())
    {
        // ������ �ݺ��Ǵ� ���� Ʈ���Ű� �ɸ� �������� �̺�Ʈ üũ
        Event event;
        while (app.pollEvent(event))
        {
            //"close ��û" �̺�Ʈ. �����츦 ����.
            if (event.type == Event::Closed) {
                app.close();
                cout << "���α׷��� ����Ǿ����ϴ�." << endl;
            }
            switch (event.type) {
            case Event::MouseButtonPressed:
            case Mouse::Left:
            {

            }
            }

            switch (event.type)
            {
            case Event:: MouseMoved:
            {
                Vector2i pos = Mouse::getPosition(app);
                cout << "�̵� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
                x = pos.x;
                y = pos.y;
                break;
                }
            }
        }
        app.clear();
        app.draw(s1);

        //�������� ��ũ���� ���
        app.display();
    }

    return 0;
}