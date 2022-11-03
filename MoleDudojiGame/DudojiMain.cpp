//(���� ���߱�) �δ��� ����
#include<SFML/Graphics.hpp>
#include<iostream>

#define WIDTH 544
#define HEIGHT 340

#define TOY_HAMMER   100.f

using namespace sf;
using namespace std;

int main(void) {
    int x = 0, y = 0;

    //���콺 �̵��� ���� ������ Circle ��ü
    CircleShape circle_shape(TOY_HAMMER);
    circle_shape.setFillColor(Color::Green);

    circle_shape.setRadius(TOY_HAMMER);
    circle_shape.setOutlineColor(sf::Color::Red);
    //circle_shape.setOutlineThickness(0); �� �׵θ�
    circle_shape.setPosition(x, y);


	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture t1;
    t1.loadFromFile("images/background.jpg");

    Sprite s1;
    s1.setTexture(t1);

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

            //���콺 ��ư ��(Released)
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
        
        //Circloe ��ġ ����
        circle_shape.setPosition(Vector2f(x - 100.f, y - 100.f));
        app.draw(circle_shape);

        //�������� ��ũ���� ���
        app.display();
    }

    return 0;
}