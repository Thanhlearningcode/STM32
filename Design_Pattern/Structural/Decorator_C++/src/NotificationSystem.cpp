#include "../inc/NotificationSystem.h"
#include <iostream>

/* Basic Notification */
Basic_Notification::Basic_Notification(const std::string& message) : message_(message) {}

void Basic_Notification:: send() const {
    std::cout<< "Sending Basic Notifcation :" << message_ << std::endl;
}

std::string Basic_Notification::Get_Message() const {
    return message_;
}

void Basic_Notification::accept(Notifcation_Visitor *visitor) const {
    visitor->visit(this);
}

Notification_Decorator::Notification_Decorator(std::shared_ptr<const Notification> notifcation) :
                                              wrapped_notification(std::move(notifcation)) {}

void Notification_Decorator::send() const {
    wrapped_notification->send();
}

std::string Notification_Decorator::Get_Message() const {
    return wrapped_notification->Get_Message();
}

void Notification_Decorator::accept(Notifcation_Visitor *visitor) const {
    wrapped_notification->accept(visitor);
}

Notification_Decorator::~Notification_Decorator() {
    
}

Email_Notification::Email_Notification(std::shared_ptr<const Notification> notifcation) :
                                        Notification_Decorator(std::move(notifcation)) {}

void Email_Notification::send() const {
    std::cout<<"Email send:"<<Get_Message()<<std::endl;
    Notification_Decorator::send();
}

SMS_Notification::SMS_Notification(std::shared_ptr<const Notification> notifcation) : Notification_Decorator(std::move(notifcation)) {}
void SMS_Notification::send() const {
    std:: cout<<"Sending SMS:"<<Get_Message()<<std::endl;
    Notification_Decorator::send();
}

Zalo_Notification::Zalo_Notification(std::shared_ptr<const Notification> notifcation) : Notification_Decorator(std::move(notifcation)) {}
void Zalo_Notification::send() const {
    std::cout <<"Sending Zalo:"<<Get_Message()<<std::endl;
    Notification_Decorator::send();
}

/*face*/
Face_Notification::Face_Notification(std::shared_ptr<const Notification> notifcation) : Notification_Decorator(std::move(notifcation)) {}
void Face_Notification::send() const {
    std::cout<<"Face send"<<Get_Message()<<std::endl;
    Notification_Decorator::send();
}

void Visitor_Logging::visit(const Notification *notification) {
    std::cout<<"Long Notification"<< notification->Get_Message()<<std::endl;
}

Noification_Manager* Noification_Manager::instance = nullptr;
Noification_Manager::Noification_Manager() {}
Noification_Manager* Noification_Manager::Get_Instance() {
    if(!instance) {
        instance = new Noification_Manager();
    }
    return instance;
}

void Noification_Manager::Send_Notification(const  Notification *notification,
                                            Notifcation_Visitor* visitor) {
notification->accept(visitor);
notification->send();                                      
}

Noification_Manager::~Noification_Manager() {
    delete instance;
}


                                    