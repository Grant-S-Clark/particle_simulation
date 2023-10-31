#include "Button.h"


void Button::set_text_font(const sf::Font & font)
{
    if (text_ == nullptr)
        text_ = new sf::Text;
    text_->setFont(font);

    adjust_text();
        
    return;
}


void Button::set_text_char_size(const int char_size)
{
    if (text_ == nullptr)
        throw NoFontError();
    text_->setCharacterSize(char_size);

    adjust_text();
        
    return;
}


void Button::set_text_color(const sf::Color & color)
{
    if (text_ == nullptr)
        throw NoFontError();

    text_fill_ = color;
    t_text_fill_ = color;
    t_text_fill_.a = 125;

    text_->setFillColor(text_fill_);

    return;
}


void Button::set_text_string(const char * str)
{
    if (text_ == nullptr)
        throw NoFontError();

    text_->setString(str);
        
    adjust_text();
    
    return;
}


void Button::setFillColor(const sf::Color & color)
{
    fill_ = color;
    t_fill_ = color;
    t_fill_.a = 125;

    sf::RectangleShape::setFillColor(fill_);

    return;
}


void Button::setOutlineColor(const sf::Color & color)
{
    outline_ = color;
    t_outline_ = color;
    t_outline_.a = 125;

    sf::RectangleShape::setOutlineColor(outline_);

    return;
}


void Button::setPosition(const float x, const float y)
{
    setPosition(sf::Vector2f(x, y));
    return;
}


void Button::setPosition(const sf::Vector2f & v)
{
    sf::RectangleShape::setPosition(v);
    if (text_ != nullptr)
        text_->setPosition(getPosition());
    
    return;
}


void Button::move(const float x, const float y)
{
    move(sf::Vector2f(x, y));
    return;
}


void Button::move(const sf::Vector2f & v)
{
    sf::RectangleShape::move(v);
    if (text_ != nullptr)
        text_->setPosition(getPosition());

    return;
}


void Button::update(const sf::RenderWindow & window)
{
    if (text_ != nullptr &&
        getPosition() != text_->getPosition())
    {
        text_->setPosition(getPosition());
    }

    //Handle transparency here.
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    if (getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
    {
        if (getFillColor().a != 0)
        {
            sf::RectangleShape::setFillColor(fill_);
            text_->setFillColor(text_fill_);
        }
    }

    else if (getFillColor().a != 125)
    {
        sf::RectangleShape::setFillColor(t_fill_);
        text_->setFillColor(t_text_fill_);
    }
    
    return;
}


bool Button::is_clicked()
{
    if (getFillColor().a != 125)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicking)
        {
            clicking = true;
            return true;
        }
    }

    //Update the clicking check boolean.
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicking)
        clicking = true;
    else if (clicking && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
        clicking = false;

    return false;
}
