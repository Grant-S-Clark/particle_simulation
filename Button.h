#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button : sf::RectangleShape
{
public:
    Button(const float x, const float y,
           sf::Color fill = sf::Color::Black,
           sf::Color outline = sf::Color::White,
           const int outline_thickness = 2) :
        sf::RectangleShape(sf::Vector2f(x, y)),
        text_(nullptr),
        fill_(fill),
        outline_(outline),
        t_fill_(fill),
        t_outline_(outline)
    {
        setFillColor(fill);
        setOutlineThickness(outline_thickness);
        setOutlineColor(outline);

        setOrigin(getSize().x / 2, getSize().y / 2);

        t_fill_.a = 125;
        t_outline_.a = 125;
        
        return;
    }

    Button(sf::Vector2f v,
           sf::Color fill = sf::Color::Black,
           sf::Color outline = sf::Color::White,
           const int outline_thickness = 2) :
        sf::RectangleShape(v),
        text_(nullptr),
        fill_(fill),
        outline_(outline),
        t_fill_(fill),
        t_outline_(outline)
    {
        setFillColor(fill);
        setOutlineThickness(outline_thickness);
        setOutlineColor(outline);

        setOrigin(getSize().x / 2, getSize().y / 2);

        t_fill_.a = 125;
        t_outline_.a = 125;
        
        return;
    }

    ~Button()
    {
        if (text_ != nullptr)
            delete text_;

        return;
    }

    // Text Functions
    void set_text_font(const sf::Font & font);
    void set_text_char_size(const int char_size);
    void set_text_color(const sf::Color & color);
    void set_text_string(const char * str);

    // Rectangle Funcitons
    void setFillColor(const sf::Color & color);
    void setOutlineColor(const sf::Color & color);
    void setPosition(const float x, const float y);
    void setPosition(const sf::Vector2f & v);
    void move(const float x, const float y);
    void move(const sf::Vector2f & v);

    // Call this function AFTER adjusting
    // the button, such as moving it. It will
    // Also handle changing colors when hovering.
    void update(const sf::RenderWindow & window);

    // Returns whether or not during this frame
    // or update cycle if you have clicked the button.
    // Will only return true on initial click, so
    // if you hold it down, the next check will return
    // false.
    bool is_clicked();
    
    // If you call a draw function in the way of
    // "window.draw(button_object);"
    // it will only draw the rectangle, and NOT
    // the text on the button. Call this function
    // to draw both.
    inline void draw(sf::RenderWindow & window) const
    {
        window.draw(*this);
        window.draw(*text_);

        return;
    }
    
private:
    //Text adjusting function.
    void adjust_text()
    {
        text_->setOrigin(text_->getGlobalBounds().left +
                         (text_->getGlobalBounds().width / 2),
                         text_->getGlobalBounds().top +
                         (text_->getGlobalBounds().height / 2));

        text_->setPosition(getPosition());
        
        return;
    }

    //Text object pointer.
    sf::Text* text_;

    //Colors
    sf::Color fill_;
    sf::Color outline_;
    sf::Color text_fill_;
    sf::Color t_fill_;
    sf::Color t_outline_;
    sf::Color t_text_fill_;

    bool clicking;
};

class NoFontError{};

#endif
