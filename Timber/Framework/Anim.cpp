#include "stdafx.h"
#include "Anim.h"

namespace fz {
    Anim::Anim()
        : m_Frames()
        , m_TotalLength(0.0)
        , m_TotalProgress(0.0)
        , m_Target(nullptr)
        , Activated(true)
        , Repeat(true)
        , m_IsEnd(false)
    {
        // Empty
    }

    Anim::~Anim()
    {
        // Empty
    }

    void Anim::SetSprite(sf::Sprite& target)
    {
        m_Target = &target;
    }

    void Anim::AddFrame(const Frame& frame)
    {
        if (m_Target == nullptr)
            return;

        m_Frames.push_back(std::move(frame));
        m_TotalLength += frame.Duration;
    }

    void Anim::Update(float dt)
    {
        m_TotalProgress += dt;

        double progress = m_TotalProgress;
        for (const auto& frame : m_Frames)
        {
            progress -= (frame).Duration;
            if (progress <= 0.0)
            {
                m_Target->setTextureRect((frame).Rect);
                break;
            }
            else if (&(frame) == &m_Frames.back())
            {
                if (Repeat || Activated)
                    this->Reset();
                else
                    m_Target->setTextureRect(m_Frames.front().Rect);
                m_IsEnd = true;
            }
        }
    }

    void Anim::Reset()
    {
        m_TotalProgress = 0.0;
        m_IsEnd = false;
    }

    void Anim::Draw(sf::RenderWindow& window)
    {
        window.draw(*m_Target);
    }

    bool Anim::IsEnd() const
    {
        return m_IsEnd;
    }

    void Anim::SetEnd(bool enabled)
    {
        m_IsEnd = enabled;
    }

} // namespace fz
