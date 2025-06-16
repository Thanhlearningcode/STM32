#include <gtest/gtest.h>
#include "../inc/NotificationSystem.h"

// Test fixture for NotificationSystem tests
class NotificationSystemTest : public ::testing::Test {
protected:
    // You can add setup/teardown if needed here
};

// Test Notification_Manager Singleton
TEST_F(NotificationSystemTest, NotificationManagerIsSingleton) {
    Noification_Manager* manager1 = Noification_Manager::Get_Instance();
    Noification_Manager* manager2 = Noification_Manager::Get_Instance();
    EXPECT_EQ(manager1, manager2); // Verify both point to the same instance
}

// Test Visitor_Logging visit
TEST_F(NotificationSystemTest, VisitorLoggingVisit) {
    Basic_Notification notification("Test log message");
    Visitor_Logging visitor;
    notification.accept(&visitor);
    // Just check message string equality
    EXPECT_EQ(notification.Get_Message(), "Test log message");
}

// Test Decorator Chain Get_Message
TEST_F(NotificationSystemTest, DecoratorChainGetMessage) {
    // Use shared_ptr to avoid manual memory management
    auto basic = std::make_shared<Basic_Notification>("Decorator test");
    auto email = std::make_shared<Email_Notification>(basic);
    auto sms = std::make_shared<SMS_Notification>(email);

    EXPECT_EQ(sms->Get_Message(), "Decorator test");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
