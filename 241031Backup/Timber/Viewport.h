#include "stdafx.h"
#pragma once


class Viewport
{
private:
    sf::View view;

public:
    Viewport(const sf::FloatRect& rect) 
    {
        view.setViewport(rect);
    }

    void SetCenter(float x, float y) {
        view.setCenter(x, y);
    }

    void SetSize(float width, float height) {
        view.setSize(width, height);
    }

    void Apply(sf::RenderWindow& window) {
        window.setView(view);
    }
};
