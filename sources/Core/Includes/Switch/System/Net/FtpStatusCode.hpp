/// @file
/// @brief Contains Switch::System::Net::FtpStatusCode enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Specifies the status codes returned for a File Transfer Protocol (FTP) operation.
      enum class FtpStatusCode {
        /// @brief Included for completeness, this value is never returned by servers.
        Undefined = 0,
        /// @brief Specifies that the response contains a restart marker reply. The text of the description that accompanies this status contains the user data stream marker and the server marker.
        RestartMarker = 110,
        /// @brief Specifies that the service is not available now; try your request later.
        ServiceTemporarilyNotAvailable = 120,
        /// @brief Specifies that the data connection is already open and the requested transfer is starting.
        DataAlreadyOpen = 125,
        /// @brief 	Specifies that the server is opening the data connection.
        OpeningData = 150,
        /// @brief Specifies that the command completed successfully.
        CommandOK = 200,
        /// @brief Specifies that the command is not implemented by the server because it is not needed.
        CommandExtraneous = 202,
        /// @brief Specifies the status of a directory.
        DirectoryStatus = 212,
        /// @brief Specifies the status of a file.
        FileStatus = 213,
        /// @brief Specifies the system type name using the system names published in the Assigned Numbers document published by the Internet Assigned Numbers Authority.
        SystemType = 215,
        /// @brief Specifies that the server is ready for a user login operation.
        SendUserCommand = 220,
        /// @brief Specifies that the server is closing the control connection.
        ClosingControl = 221,
        /// @brief Specifies that the server is closing the data connection and that the requested file action was successful.
        ClosingData = 226,
        /// @brief Specifies that the server is entering passive mode.
        EnteringPassive = 227,
        /// @brief Specifies that the user is logged in and can send commands.
        LoggedInProceed = 230,
        /// @brief Specifies that the server accepts the authentication mechanism specified by the client, and the exchange of security data is complete.
        ServerWantsSecureSession = 231,
        /// @brief Specifies that the requested file action completed successfully.
        FileActionOK = 250,
        /// @brief Specifies that the requested path name was created.
        PathnameCreated = 257,
        /// @brief Specifies that the server expects a password to be supplied.
        SendPasswordCommand = 331,
        /// @brief Specifies that the server requires a login account to be supplied.
        NeedLoginAccount = 332,
        /// @brief Specifies that the requested file action requires additional information.
        FileCommandPending = 350,
        /// @brief Specifies that the service is not available.
        ServiceNotAvailable = 421,
        /// @brief Specifies that the data connection cannot be opened.
        CantOpenData = 425,
        /// @brief Specifies that the connection has been closed.
        ConnectionClosed = 426,
        /// @brief Specifies that the requested action cannot be performed on the specified file because the file is not available or is being used.
        ActionNotTakenFileUnavailableOrBusy = 450,
        /// @brief Specifies that an error occurred that prevented the request action from completing.
        ActionAbortedLocalProcessingError = 451,
        /// @brief Specifies that the requested action cannot be performed because there is not enough space on the server.
        ActionNotTakenInsufficientSpace = 452,
        /// @brief 	Specifies that the command has a syntax error or is not a command recognized by the server.
        CommandSyntaxError = 500,
        /// @brief Specifies that one or more command arguments has a syntax error.
        ArgumentSyntaxError = 501,
        /// @brief Specifies that the command is not implemented by the FTP server.
        CommandNotImplemented = 502,
        /// @brief Specifies that the sequence of commands is not in the correct order.
        BadCommandSequence = 503,
        /// @brief Specifies that login information must be sent to the server.
        NotLoggedIn = 530,
        /// @brief Specifies that a user account on the server is required.
        AccountNeeded = 532,
        /// @brief Specifies that the requested action cannot be performed on the specified file because the file is not available.
        ActionNotTakenFileUnavailable = 550,
        /// @brief Specifies that the requested action cannot be taken because the specified page type is unknown. Page types are described in RFC 959 Section 3.1.2.3.
        ActionAbortedUnknownPageType = 551,
        /// @brief Specifies that the requested action cannot be performed.
        FileActionAborted = 552,
        /// @brief Specifies that the requested action cannot be performed on the specified file.
        ActionNotTakenFilenameNotAllowed = 553
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Net::FtpStatusCode> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Net::FtpStatusCode::Undefined, "Undefined"}, {(int64)System::Net::FtpStatusCode::RestartMarker, "RestartMarker"}, {(int64)System::Net::FtpStatusCode::ServiceTemporarilyNotAvailable, "ServiceTemporarilyNotAvailable"}, {(int64)System::Net::FtpStatusCode::DataAlreadyOpen, "DataAlreadyOpen"}, {(int64)System::Net::FtpStatusCode::OpeningData, "OpeningData"}, {(int64)System::Net::FtpStatusCode::CommandOK, "CommandOK"}, {(int64)System::Net::FtpStatusCode::CommandExtraneous, "CommandExtraneous"}, {(int64)System::Net::FtpStatusCode::DirectoryStatus, "DirectoryStatus"}, {(int64)System::Net::FtpStatusCode::FileStatus, "FileStatus"}, {(int64)System::Net::FtpStatusCode::SystemType, "SystemType"}, {(int64)System::Net::FtpStatusCode::SendUserCommand, "SendUserCommand"}, {(int64)System::Net::FtpStatusCode::ClosingControl, "ClosingControl"}, {(int64)System::Net::FtpStatusCode::ClosingData, "ClosingData"}, {(int64)System::Net::FtpStatusCode::EnteringPassive, "EnteringPassive"}, {(int64)System::Net::FtpStatusCode::LoggedInProceed, "LoggedInProceed"}, {(int64)System::Net::FtpStatusCode::ServerWantsSecureSession, "ServerWantsSecureSession"}, {(int64)System::Net::FtpStatusCode::FileActionOK, "FileActionOK"}, {(int64)System::Net::FtpStatusCode::PathnameCreated, "PathnameCreated"}, {(int64)System::Net::FtpStatusCode::SendPasswordCommand, "SendPasswordCommand"}, {(int64)System::Net::FtpStatusCode::NeedLoginAccount, "NeedLoginAccount"}, {(int64)System::Net::FtpStatusCode::FileCommandPending, "FileCommandPending"}, {(int64)System::Net::FtpStatusCode::ServiceNotAvailable, "ServiceNotAvailable"}, {(int64)System::Net::FtpStatusCode::CantOpenData, "CantOpenData"}, {(int64)System::Net::FtpStatusCode::ConnectionClosed, "ConnectionClosed"}, {(int64)System::Net::FtpStatusCode::ActionNotTakenFileUnavailableOrBusy, "ActionNotTakenFileUnavailableOrBusy"}, {(int64)System::Net::FtpStatusCode::ActionAbortedLocalProcessingError, "ActionAbortedLocalProcessingError"}, {(int64)System::Net::FtpStatusCode::ActionNotTakenInsufficientSpace, "ActionNotTakenInsufficientSpace"}, {(int64)System::Net::FtpStatusCode::CommandSyntaxError, "CommandSyntaxError"}, {(int64)System::Net::FtpStatusCode::ArgumentSyntaxError, "ArgumentSyntaxError"}, {(int64)System::Net::FtpStatusCode::CommandNotImplemented, "CommandNotImplemented"}, {(int64)System::Net::FtpStatusCode::BadCommandSequence, "BadCommandSequence"}, {(int64)System::Net::FtpStatusCode::NotLoggedIn, "NotLoggedIn"}, {(int64)System::Net::FtpStatusCode::AccountNeeded, "AccountNeeded"}, {(int64)System::Net::FtpStatusCode::ActionNotTakenFileUnavailable, "ActionNotTakenFileUnavailable"}, {(int64)System::Net::FtpStatusCode::ActionAbortedUnknownPageType, "ActionAbortedUnknownPageType"}, {(int64)System::Net::FtpStatusCode::FileActionAborted, "FileActionAborted"}, {(int64)System::Net::FtpStatusCode::ActionNotTakenFilenameNotAllowed, "ActionNotTakenFilenameNotAllowed"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
