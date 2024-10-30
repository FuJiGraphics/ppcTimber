#pragma once

namespace fz {

    class Camera;

    struct Frame 
    {
        sf::IntRect Rect;
        double Duration;
    };

    class Anim
    {
    public:
        bool Activated;
        bool Repeat;

    public:
        Anim();
        virtual ~Anim();
        void SetSprite(sf::Sprite& target);
        void AddFrame(const Frame& frame);
        void Update(float dt);
        void Reset();
        void Draw(sf::RenderWindow& window);
        bool IsEnd() const;
        void SetEnd(bool enabled);

        // TODO: юс╫ц
        inline sf::Sprite* GetSprite() { return m_Target; }
        inline sf::Sprite* GetSprite() const { return m_Target; }

    private:
        std::vector<Frame> m_Frames;
        double m_TotalLength;
        double m_TotalProgress;
        sf::Sprite* m_Target;
        bool m_IsEnd;
    };

} // namespace fz