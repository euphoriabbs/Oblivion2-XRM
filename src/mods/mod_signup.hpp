#ifndef MOD_SIGNUP_HPP
#define MOD_SIGNUP_HPP

#include "mod_base.hpp"

#include "../model/structures.hpp"
#include "../model/users.hpp"
#include "../data/text_prompts_dao.hpp"
#include "../data/users_dao.hpp"

#include "../session_data.hpp"
#include "../session_io.hpp"

#include <vector>
#include <functional>

/**
 * @class ModSignup
 * @author Michael Griffin
 * @date 3/28/2016
 * @file mod_signup.hpp
 * @brief New User Application Module
 */
class ModSignup
    : public ModBase
{
public:
    ModSignup(session_data_ptr session_data)
        : ModBase(session_data)
        , m_session_io(session_data)
        , m_filename("mod_signup.yaml")
        , m_text_prompts_dao(new TextPromptsDao(GLOBAL_DATA_PATH, m_filename))
        , m_user_record(new Users())
        , m_mod_function_index(MOD_NUP)
        , m_is_text_prompt_exist(false)
    {
        std::cout << "ModSignup" << std::endl;

        // Push function pointers to the stack.
        m_setup_functions.push_back(std::bind(&ModSignup::setupNewUserPassword, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupDisclaimer, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupHandle, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupRealName, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupAddress, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupLocation, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupCountry, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupEmail, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupUserNote, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupBirthday, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupGender, this));

        m_setup_functions.push_back(std::bind(&ModSignup::setupPassword, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupVerifyPassword, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupChallengeQuestion, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupChallengeAnswer, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupVerifyChallengeAnswer, this));

        m_setup_functions.push_back(std::bind(&ModSignup::setupYesNoBars, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupDoPause, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupClearOrScroll, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupAnsiColor, this));
        m_setup_functions.push_back(std::bind(&ModSignup::setupBackSpace, this));

        // Input Processing Functions
        m_mod_functions.push_back(std::bind(&ModSignup::newUserPassword, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::disclaimer, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::handle, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::realName, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::address, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::location, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::country, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::email, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::userNote, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::birthday, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::gender, this, std::placeholders::_1));

        m_mod_functions.push_back(std::bind(&ModSignup::password, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::verifyPassword, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::challengeQuestion, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::challengeAnswer, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::verifyChallengeAnswer, this, std::placeholders::_1));

        m_mod_functions.push_back(std::bind(&ModSignup::yesNoBars, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::doPause, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::clearOrScroll, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::ansiColor, this, std::placeholders::_1));
        m_mod_functions.push_back(std::bind(&ModSignup::backSpace, this, std::placeholders::_1));

        // Check of the Text Prompts exist.
        m_is_text_prompt_exist = m_text_prompts_dao->fileExists();
        if (!m_is_text_prompt_exist)
        {
            createTextPrompts();
        }

        // Loads all Text Prompts for current module
        m_text_prompts_dao->readPrompts();
    }

    virtual ~ModSignup()
    {
        std::cout << "~ModSignup" << std::endl;
        std::vector<std::function< void()> >().swap(m_setup_functions);
        std::vector<std::function< void(const std::string &)> >().swap(m_mod_functions);
    }

    virtual bool update(const std::string &character_buffer, const bool &);
    virtual bool onEnter();
    virtual bool onExit();

    // This matches the index for mod_functions.push_back
    enum
    {
        MOD_NUP,
        MOD_DISCLAIMER,
        MOD_HANDLE,
        MOD_REALNAME,
        MOD_ADDRESS,
        MOD_LOCATION,
        MOD_COUNTRY,
        MOD_EMAIL,
        MOD_USERNOTE,
        MOD_BIRTHDATE,
        MOD_GENDER,
        MOD_PASSWORD,
        MOD_PASSOWRD_VERIFY,
        MOD_CHALLENGE_QUEST,
        MOD_CHALLENGE_ANSWER,
        MOD_CHALLENGE_VERIFY,
        MOD_YESNOBARS,
        MOD_PAUSE,
        MOD_CLEAR_SCREEN,
        MOD_ANSI_COLOR,
        MOD_BACKSPACE
    };

    // Create Prompt Constants, these are the keys for key/value lookup
    const std::string PROMPT_NUP = "new_user_password";
    const std::string PROMPT_HANDLE = "handle";
    const std::string PROMPT_REAL_NAME = "real_name";
    const std::string PROMPT_ADDRESS = "address";
    const std::string PROMPT_LOCATION = "location";
    const std::string PROMPT_COUNTRY = "country";
    const std::string PROMPT_EMAIL = "email";
    const std::string PROMPT_USER_NOTE = "user_note";
    const std::string PROMPT_BIRTH_DATE = "birth_date";
    // ... cont


    /**
     * @brief Create Default Text Prompts for module
     */
    void createTextPrompts();

    /**
     * @brief Sets an indivdual module index.
     * @param mod_function_index
     */
    void changeModule(int mod_function_index);

    /**
     * @brief New User Password
     * @return
     */
    void setupNewUserPassword();

    /**
     * @brief Pre Application Disclaimer
     * @return
     */
    void setupDisclaimer();
    
    /**
     * @brief Get Handle from User
     * @return
     */
    void setupHandle();

    /**
     * @brief Get Real Name
     * @return
     */
    void setupRealName();

    /**
     * @brief Get Address
     * @return
     */
    void setupAddress();

    /**
     * @brief Get Location
     * @return
     */
    void setupLocation();

    /**
     * @brief Get Country
     * @return
     */
    void setupCountry();

    /**
     * @brief Get Email
     * @return
     */
    void setupEmail();

    /**
     * @brief Get UserNote
     * @return
     */
    void setupUserNote();

    /**
     * @brief Get Birthdate
     * @return
     */
    void setupBirthday();

    /**
     * @brief Get Gender
     * @return
     */
    void setupGender();

    /**
     * @brief Get Password
     * @return
     */
    void setupPassword();

    /**
     * @brief Verify Password
     * @return
     */
    void setupVerifyPassword();

    /**
     * @brief Set Password Reset Challenge Question
     * @return
     */
    void setupChallengeQuestion();

    /**
     * @brief Set Password Reset Challenge Answer
     * @return
     */
    void setupChallengeAnswer();

    /**
     * @brief Set Password Reset Challenge Answer
     * @return
     */
    void setupVerifyChallengeAnswer();

    /**
     * @brief Get Yes / No Bar Preference
     * @return
     */
    void setupYesNoBars();

    /**
     * @brief Get Pause Preference
     * @return
     */
    void setupDoPause();

    /**
     * @brief Get Clear or Scroll preference
     * @return
     */
    void setupClearOrScroll();

    /**
     * @brief Get ANSI Color preference
     * @return
     */
    void setupAnsiColor();

    /**
     * @brief Get Backspace Preference WINDOWS/LINUX (Terminal)
     * @return
     */
    void setupBackSpace();

private:

    /**
     * @brief New User Password
     * @return
     */
    bool newUserPassword(const std::string &input);

    /**
     * @brief Pre Application Disclaimer
     * @return
     */
    bool disclaimer(const std::string &input);

    /**
     * @brief Get Handle from User
     * @return
     */
    bool handle(const std::string &input);

    /**
     * @brief Get Real Name
     * @return
     */
    bool realName(const std::string &input);

    /**
     * @brief Get Address
     * @return
     */
    bool address(const std::string &input);

    /**
     * @brief Get Location
     * @return
     */
    bool location(const std::string &input);

    /**
     * @brief Get Country
     * @return
     */
    bool country(const std::string &input);

    /**
     * @brief Get Email
     * @return
     */
    bool email(const std::string &input);

    /**
     * @brief Get UserNote
     * @return
     */
    bool userNote(const std::string &input);

    /**
     * @brief Get Birthdate
     * @return
     */
    bool birthday(const std::string &input);

    /**
     * @brief Get Gender
     * @return
     */
    bool gender(const std::string &input);

    /**
     * @brief Get Password
     * @return
     */
    bool password(const std::string &input);

    /**
     * @brief Verify Password
     * @return
     */
    bool verifyPassword(const std::string &input);

    /**
     * @brief Set Password Reset Challenge Question
     * @return
     */
    bool challengeQuestion(const std::string &input);

    /**
     * @brief Set Password Reset Challenge Answer
     * @return
     */
    bool challengeAnswer(const std::string &input);

    /**
     * @brief Set Password Reset Challenge Answer
     * @return
     */
    bool verifyChallengeAnswer(const std::string &input);

    /**
     * @brief Get Yes / No Bar Preference
     * @return
     */
    bool yesNoBars(const std::string &input);

    /**
     * @brief Get Pause Preference
     * @return
     */
    bool doPause(const std::string &input);

    /**
     * @brief Get Clear or Scroll preference
     * @return
     */
    bool clearOrScroll(const std::string &input);

    /**
     * @brief Get ANSI Color preference
     * @return
     */
    bool ansiColor(const std::string &input);

    /**
     * @brief Get Backspace Preference WINDOWS/LINUX (Terminal)
     * @return
     */
    bool backSpace(const std::string &input);

    // Function Input Vector.
    std::vector<std::function< void()> >                    m_setup_functions;
    std::vector<std::function< void(const std::string &)> > m_mod_functions;

    SessionIO            m_session_io;
    std::string          m_filename;
    text_prompts_dao_ptr m_text_prompts_dao;
    user_ptr             m_user_record;

    int                  m_mod_function_index;
    bool                 m_is_text_prompt_exist;
};

#endif // MOD_SIGNUP_HPP
