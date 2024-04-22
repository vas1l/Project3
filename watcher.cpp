#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void printFileContents(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath << std::endl;
        return;
    }
    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void watchFile(const std::string& directoryPath, const std::string& targetFilename) {
    char buffer[4096]; // Larger buffer
    DWORD bytesReturned;
    FILE_NOTIFY_INFORMATION* notify;

    HANDLE dirHandle = CreateFile(
        directoryPath.c_str(),
        FILE_LIST_DIRECTORY,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED,
        NULL
    );

    if (dirHandle == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to open directory for watching. Code: " << GetLastError() << std::endl;
        return;
    }

    OVERLAPPED overlapped = {};
    overlapped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL); // Manual reset event

    if (!ReadDirectoryChangesW(
        dirHandle,
        buffer,
        sizeof(buffer),
        FALSE,
        FILE_NOTIFY_CHANGE_LAST_WRITE,
        &bytesReturned,
        &overlapped,
        NULL
    )) {
        std::cerr << "ReadDirectoryChangesW initial call failed. Error: " << GetLastError() << std::endl;
        CloseHandle(dirHandle);
        return;
    }

    while (true) {
        DWORD waitStatus = WaitForSingleObject(overlapped.hEvent, INFINITE);
        if (waitStatus == WAIT_OBJECT_0) {
            if (GetOverlappedResult(dirHandle, &overlapped, &bytesReturned, FALSE) && bytesReturned != 0) {
                do {
                    notify = (FILE_NOTIFY_INFORMATION*)buffer;
                    std::wstring fileName(notify->FileName, notify->FileNameLength / sizeof(WCHAR));
                    std::string narrowFileName(fileName.begin(), fileName.end());
                    if (narrowFileName == targetFilename) {
                        std::cout << "Detected a change in: " << narrowFileName << std::endl;
                        printFileContents(directoryPath + "\\" + narrowFileName);
                    }

                    if (notify->NextEntryOffset == 0) break;
                    notify = (FILE_NOTIFY_INFORMATION*)((char*)notify + notify->NextEntryOffset);
                } while (notify != NULL);

                ResetEvent(overlapped.hEvent);
                memset(buffer, 0, sizeof(buffer));
                if (!ReadDirectoryChangesW(
                    dirHandle,
                    buffer,
                    sizeof(buffer),
                    FALSE,
                    FILE_NOTIFY_CHANGE_LAST_WRITE,
                    &bytesReturned,
                    &overlapped,
                    NULL
                )) {
                    std::cerr << "ReadDirectoryChangesW re-call failed. Error: " << GetLastError() << std::endl;
                    break;
                }
            }
        }
    }

    CloseHandle(overlapped.hEvent);
    CloseHandle(dirHandle);
}

int watch() {
    std::string directory = "C:\\Users\\dalva\\OneDrive\\Desktop\\Project3\\Project3"; //replace with your path
    std::string filename = "country.txt";

    watchFile(directory, filename);
    return 0;
}