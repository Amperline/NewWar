#include "Registration.h"
#include "ButtonController.h"

bool Registration(sf::RenderWindow* window, sf::TcpSocket* connector)
{
    sf::IpAddress s_ipAdrres("");
    sf::IpAddress l_ipAdrres("127.0.0.1");
    unsigned short s_port = 4097;

    enum Registration
    {
        INMENU,
        LOGIN,
        SIGNUP
    };
    Registration RegStatus{ Registration::INMENU };

    Menu RegMenu(window, UseVariation::Imgs, "resource/images/MainMenu/MainMenu", 300, 12);
    Button logIn(window, "resource/images/Buttons/Button", 128 * 6, 40 * 6);
    Button SignUp(window, "resource/images/Buttons/Button", 128 * 6, 66 * 6);
    Button Back(window, "resource/images/Buttons/Button", 128 * 6, 92 * 6);
    logIn.getText().setCharacterSize(34);
    SignUp.getText().setCharacterSize(34);
    logIn.setupFont("Log in", 26, 4);
    SignUp.setupFont("Sign up", 14, 4);
    Back.setupFont("Back", 26, 0);
    


    Button EnterLogIn(window, "resource/images/Buttons/Button", 128 * 6, 92 * 6);
    EnterLogIn.setupFont("Enter", 18, 0);
    Button EnterSignUp(window, "resource/images/Buttons/Button", 128 * 6, 92 * 6);
    EnterSignUp.setupFont("Enter", 18, 0);
    Field LoginName(window, "resource/images/DynamicField/DynamicField", 123 * 6, 40 * 6);
    Field LoginPassword(window, "resource/images/DynamicField/DynamicField", 123 * 6, 66 * 6);

    Button BackLogIn(window, "resource/images/Buttons/Button", 128 * 6, 118 * 6);
    BackLogIn.setupFont("Back", 26, 0);
    Button BackSignUp(window, "resource/images/Buttons/Button", 128 * 6, 118 * 6);
    BackSignUp.setupFont("Back", 26, 0);
    Field SignUpName(window, "resource/images/DynamicField/DynamicField", 123 * 6, 40 * 6);
    Field SignUpPassword(window, "resource/images/DynamicField/DynamicField", 123 * 6, 66 * 6);

    sf::Uint8 opacity = 120;
    GameString s1("resource/fonts/NewWar", window, 11);
    s1.getText().setCharacterSize(40);
    s1.getText().setPosition((131 * 6) - 12, (43 * 6) + 2);
    s1.setCangeAble(1);
    s1.setShowa(0);
    s1.getText().setFillColor(sf::Color(152, 32, 32));

    sf::Font f;
    f.loadFromFile("resource/fonts/NewWar.ttf");
    sf::Text Default;
    Default.setFont(f);
    Default.setPosition((131 * 6) - 2, (43 * 6) + 2);
    Default.setString("Nickname");
    Default.setCharacterSize(40);
    Default.setFillColor(sf::Color(41, 192, 51, opacity));

    GameString s2("resource/fonts/NewWar", window, 9);
    s2.getText().setCharacterSize(40);
    s2.getText().setPosition((131 * 6) - 2, (69 * 6) + 2);
    s2.setCangeAble(1);
    s2.setShowa(0);
    s2.getText().setFillColor(sf::Color(152, 32, 32));

    sf::Text Default2;
    Default2.setFont(f);
    Default2.setPosition((131 * 6) - 2, (69 * 6) + 2);
    Default2.setString("Password");
    Default2.setCharacterSize(40);
    Default2.setFillColor(sf::Color(41, 192, 51, opacity));

    while (window->isOpen())
    {
        ConnectorPacket SendData;
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        RegMenu.checkAll();
        if (GetButtonlogicPress(logIn))
        {
            RegStatus = Registration::LOGIN;
        }
        else if(GetButtonlogicPress(SignUp))
        {
            RegStatus = Registration::SIGNUP;
        }
        else if(GetButtonlogicPress(Back))
        {
            return false;
        }
        try
        {
            bool ConnSucc = 0;
            std::string error;

            bool isExecute = 0;
            bool LorS = 0;

            if (GetButtonlogicPress(EnterLogIn)) { isExecute = 1; LorS = 1; }
            if (GetButtonlogicPress(EnterSignUp)) { isExecute = 1; LorS = 0; }
            if (isExecute == 1)
            {
                sf::Socket::Status status;
                status = connector->connect(l_ipAdrres, s_port, sf::milliseconds(800));
                if (status != sf::Socket::Done)
                {
                    makeError(window, "Error: Fail to connect!");
                    return 0;
                }
                if (LorS == 1)
                {
                    SendData.LorC = 1;
                    SendData.Name = sf::String(s1.getStr());
                    SendData.Password = sf::String(s2.getStr());

                    sf::Packet packet;
                    packet << SendData.LorC << SendData.Name << SendData.Password;
                    connector->send(packet);

                    sf::Packet p;
                    connector->receive(p);
                    p >> ConnSucc >> error;

                    if (ConnSucc == 1)
                    {
                        throw std::string("Success!");
                        return true;
                    }
                    else if (ConnSucc == 0)
                    {
                        throw error;
                    }
                }
                if (LorS == 0)
                {
                    SendData.LorC = 0;
                    SendData.Name = sf::String(s1.getStr());
                    SendData.Password = sf::String(s2.getStr());

                    sf::Packet packet;
                    packet << SendData.LorC << SendData.Name << SendData.Password;
                    connector->send(packet);

                    sf::Packet p;
                    connector->receive(p);
                    p >> ConnSucc >> error;

                    if (ConnSucc == 1)
                    {
                        RegStatus = Registration::INMENU;
                        s1.getStr().clear();
                        s2.getStr().clear();
                        s1.getText().setString(s1.getStr());
                        s2.getText().setString(s2.getStr());
                        s1.setShowa(0);
                        s2.setShowa(0);
                    }
                    else if (ConnSucc == 0)
                    {
                        throw error;
                    }
                }
            }
            if (GetButtonlogicPress(BackLogIn))
            {
                RegStatus = Registration::INMENU;
                s1.getStr().clear();
                s2.getStr().clear();
                s1.getText().setString(s1.getStr());
                s2.getText().setString(s2.getStr());
                s1.setShowa(0);
                s2.setShowa(0);
            }
            if (GetButtonlogicPress(BackSignUp))
            {
                RegStatus = Registration::INMENU;
                s1.getStr().clear();
                s2.getStr().clear();
                s1.getText().setString(s1.getStr());
                s2.getText().setString(s2.getStr());
                s1.setShowa(0);
                s2.setShowa(0);
            }
        }
        catch(const std::string ex)
        {
            makeError(window, "Error: " + ex);
            s1.getStr().clear();
            s2.getStr().clear();
            s1.getText().setString(s1.getStr());
            s2.getText().setString(s2.getStr());
            s1.setShowa(0);
            s2.setShowa(0);
        }

        if(RegStatus == Registration::INMENU)
        {
            logIn.checkAll();
            SignUp.checkAll();
            Back.checkAll();
        }
        else if(RegStatus == Registration::LOGIN)
        {
            BackLogIn.checkAll();
            EnterLogIn.checkAll();
            LoginName.checkAll();
            LoginPassword.checkAll();
            if (LoginName.isCuttrntField())
            {
                s1.checkText();
            }
            else if (LoginPassword.isCuttrntField())
            {
                s2.checkText();
            }
        }
        else if(RegStatus == Registration::SIGNUP)
        {
            EnterSignUp.checkAll();
            BackSignUp.checkAll();
            SignUpName.checkAll();
            SignUpPassword.checkAll();
            if(SignUpName.isCuttrntField())
            {
                s1.checkText();
            }
            else if(SignUpPassword.isCuttrntField())
            {
                s2.checkText();
            }
        }

        window->clear();
        RegMenu.draw();
        if (RegStatus == Registration::INMENU)
        {
            logIn.draw();
            SignUp.draw();
            Back.draw();
        }
        else if (RegStatus == Registration::LOGIN)
        {
            EnterLogIn.draw();
            BackLogIn.draw();
            LoginName.draw();
            LoginPassword.draw();
            s1.draw();
            s2.draw();
            if (s1.getShowAble() == 0) { window->draw(Default); }
            if (s2.getShowAble() == 0) { window->draw(Default2); }
        }
        else if (RegStatus == Registration::SIGNUP)
        {
            EnterSignUp.draw();
            BackSignUp.draw();
            SignUpName.draw();
            SignUpPassword.draw();
            s1.draw();
            s2.draw();
            if (s1.getShowAble() == 0) { window->draw(Default); }
            if (s2.getShowAble() == 0) { window->draw(Default2); }
        }
        window->display();
    }
    return 0;
}