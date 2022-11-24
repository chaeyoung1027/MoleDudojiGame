//(���� ���߱�) �δ��� ����
#include<SFML/Graphics.hpp>
#include<iostream>

#define WIDTH 1100
#define HEIGHT 942

using namespace sf;
using namespace std;

struct Position
{
    int x;
    int y;
};

int main(void) {


	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture t1, t2, t3, t4, t5, t6, t7, t8;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/hammer.png");
    t3.loadFromFile("images/hammer_pressed.png");
    /*t4.loadFromFile("images/�δ���1.png");
    t5.loadFromFile("images/�δ���2.png");
    t6.loadFromFile("images/�δ���3.png");
    t7.loadFromFile("images/�δ���4.png");
    t8.loadFromFile("images/�δ���5.png");
    t9.loadFromFile("images/�δ���6.png");*/

    Sprite background(t1);

    Sprite hammer[2];
    hammer[0] = Sprite(t2);
    hammer[1] = Sprite(t3);

    Sprite Dudoji[6];

    Sprite s(t2);

    Position hammerPos;
    hammerPos.x = 0;
    hammerPos.y = 0;

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
            //���콺�� ������ ��
            switch (event.type) {
                case Event::MouseButtonPressed:
                case Mouse::Left:
                {
                    s = hammer[1];
                    printf("���콺");
                    break;
                }
            }
            //���콺�� ������ ��MouseButtonReleased
            switch (event.type) {
            case Event::MouseButtonReleased:
            case Mouse::Left:
            {
                s = hammer[0];
                break;
            }
            }

            //���콺�� ������ ��
            switch (event.type)
            {
            case Event:: MouseMoved:
            {
                Vector2i pos = Mouse::getPosition(app);
                cout << "�̵� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
                hammerPos.x = pos.x;
                hammerPos.y = pos.y;
                break;
                }
            }
            s.setPosition(hammerPos.x-70, hammerPos.y-77);
        }
        app.clear();
        app.draw(background);
        app.draw(s);

        //�������� ��ũ���� ���
        app.display();
    }

    return 0;
}