#pragma once
#include <memory>
#include <string>

// Forward Declaration
class Notifcation_Visitor;

// Abstract Notification Class
class Notification {
public:
    virtual void send() const = 0;
    virtual std::string Get_Message() const = 0;
    virtual void accept(Notifcation_Visitor* visitor) const = 0;
    virtual ~Notification() = default;
};

// Concrete Notification Class
class Basic_Notification : public Notification {
public:
    explicit Basic_Notification(const std::string& message);
    void send() const override;
    std::string Get_Message() const override;
    void accept(Notifcation_Visitor* visitor) const override;

private:
    std::string message_;
};

// Abstract Decorator Class
class Notification_Decorator : public Notification {
public:
    explicit Notification_Decorator(std::shared_ptr<const Notification> notifcation);
    void send() const override;
    std::string Get_Message() const override;
    void accept(Notifcation_Visitor* visitor) const override;
    ~Notification_Decorator();

protected:
    std::shared_ptr<const Notification> wrapped_notification;
};

// Email Decorator
class Email_Notification : public Notification_Decorator {
public:
    explicit Email_Notification(std::shared_ptr<const Notification> notifcation);
    void send() const override;
};

// SMS Decorator
class SMS_Notification : public Notification_Decorator {
public:
    explicit SMS_Notification(std::shared_ptr<const Notification> notifcation);
    void send() const override;
};

// Zalo Decorator
class Zalo_Notification : public Notification_Decorator {
public:
    explicit Zalo_Notification(std::shared_ptr<const Notification> notifcation);
    void send() const override;
};

// Face Decorator
class Face_Notification : public Notification_Decorator {
public:
    explicit Face_Notification(std::shared_ptr<const Notification> notifcation);
    void send() const override;
};

// Visitor Interface
class Notifcation_Visitor {
public:
    virtual void visit(const Notification* notification) = 0;
    virtual ~Notifcation_Visitor() = default;
};

// Logging Visitor
class Visitor_Logging : public Notifcation_Visitor {
public:
    void visit(const Notification* notification) override;
};

// Singleton Notification Manager
class Noification_Manager {
private:
    static Noification_Manager* instance;
    Noification_Manager();
    ~Noification_Manager();

public:
    static Noification_Manager* Get_Instance();
    void Send_Notification(const Notification* notification, Notifcation_Visitor* visitor);

    Noification_Manager(const Noification_Manager&) = delete;
    Noification_Manager& operator=(const Noification_Manager&) = delete;
};