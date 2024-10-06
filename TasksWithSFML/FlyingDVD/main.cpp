#include <SFML/Graphics.hpp>
#include "level.h"
using namespace sf;


void getplayercoordinateforview(float x,float y, View& view) { //функция для считывания координат игрока
    view.setCenter(x + 100, y); //следим за игроком, передавая его координаты камере. +100 - сместили камеру по иксу вправо. эксперементируйте
}

View view;
class Player
{
private:
    std::vector<Object> obj; // Вектор объектов карты
    float dx, dy, x, y, speed;
    int w, h; // Ширина и высота тайла
    Texture texture;
    Sprite sprite;
public:
    Player(Image &image, std::vector<Object>& _obj, float X, float Y, int W, int H){
        x = X; y = Y; w = W; h = H;
        speed = 0.5; dx = speed; dy = speed;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
        obj = _obj;
    }


    int getX() {return x;}
    int getY() {return y;}


    // функция получения прямоугольника. координаты объекта, размер (ширина, высота).
    FloatRect getRect(){ return FloatRect(x, y, w, h); }// нужна для проверки столкновений

    // Проверяем Столкновения Нашего Игрока с Другими Тайлами Карты
    void checkCollisionWithMap(float Dx, float Dy)
    {
        for (size_t i = 0; i < obj.size(); i++) // Проходимся по всем элементам карты
            if (getRect().intersects(obj[i].rect)) // Если мы пересекаемся с каким-то тайликом
            {
                if (obj[i].name == "solid") // И этот тайлик помечен знаком "Стена"
                {
                    if (Dy>0)	{ y = obj[i].rect.top - h;  dy *= -1;; }
                    else if (Dy<0)	{ y = obj[i].rect.top + obj[i].rect.height;   dy *= -1; }
                    if (Dx>0)	{ x = obj[i].rect.left - w; dx *= -1;}
                    else if (Dx<0)	{ x = obj[i].rect.left + obj[i].rect.width; dx *= -1;}
                }
            }
    }

    void update(float time)
    {
        x += dx*time;
        checkCollisionWithMap(dx, 0);
        y += dy*time;
        checkCollisionWithMap(0, dy);
        sprite.setPosition(x + w / 2, y + h / 2);
        getplayercoordinateforview(x, y, view);
    }

    Sprite getSprite()  { return sprite;}
};


int main()
{


    //////////////////////////////СОЗДАЁМ ОКНО//////////////////////////////
    RenderWindow window(VideoMode(1600, 1250), "FlyingDVD");  // Создаём окно
    view.reset(FloatRect(0, 0, 1300, 1050));
    //////////////////////////////ЗАГРУЖАЕМ КАРТУ//////////////////////////////
    Level lvl; // Создаём объект типа "Карта"
    lvl.LoadFromFile("../../map.tmx");  // Загружаем нашу карту
    std::vector<Object> obj = lvl.GetAllObjects(); // Получаем вектор объектов карты

    //////////////////////////////СОЗДАЁМ ИГРОКА//////////////////////////////
    Image heroImage;
    heroImage.loadFromFile("../../images/sasha.jpg");
    heroImage.createMaskFromColor(Color(0,0,0,0));
    Object player = lvl.GetObject("player");
    Player object(heroImage, obj, player.rect.left, player.rect.top, 207, 207);//72 83 player

    // Создаём часики для работы со временем
    Clock clock;
    while (window.isOpen())
    {
        window.clear(Color::Black);
        window.setView(view);

        //////////////////////////////ВРЕМЯ//////////////////////////////
        float time = clock.getElapsedTime().asMicroseconds(); // Берём у часиков время
        clock.restart(); // Запускаем часики
        time = time / 800; // Уменьшаем время, чтобы не так быстро всё летало


        //////////////////////////////ДАРИМ ИГРЕ ЖИЗНЬ//////////////////////////////
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //////////////////////////////РИСУЕМ КАРТУ//////////////////////////////
        lvl.Draw(window);


        //////////////////////////////ДАРИМ ИГРОКУ ЖИЗНЬ//////////////////////////////
        object.update(time);
        window.draw(object.getSprite()); // Рисуем игрока

        window.display(); // Показываем наше игровое окно
    }
    return 0;
}

