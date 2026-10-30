#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <chrono>

using namespace geode::prelude;

class $modify(CPSLimiterPlayer, PlayerObject) {
    struct Fields {
        std::chrono::steady_clock::time_point lastAcceptedClick{};
        bool hasAcceptedClick = false;
    };

    void pushButton(PlayerButton button) {
        // Only apply the limiter while a normal gameplay layer is active.
        if (!PlayLayer::get()) {
            PlayerObject::pushButton(button);
            return;
        }

        auto cps = Mod::get()->getSettingValue<int64_t>("target-cps");
        cps = std::clamp<int64_t>(cps, 10, 17);
        auto minimumInterval = std::chrono::duration<double>(1.0 / static_cast<double>(cps));
        auto now = std::chrono::steady_clock::now();

        if (m_fields->hasAcceptedClick) {
            auto elapsed = now - m_fields->lastAcceptedClick;
            if (elapsed < minimumInterval) {
                return; // Ignore this press because it exceeds the selected CPS cap.
            }
        }

        m_fields->lastAcceptedClick = now;
        m_fields->hasAcceptedClick = true;
        PlayerObject::pushButton(button);
    }
};
