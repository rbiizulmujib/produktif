repeat
    try
        tell application "Safari"
            set currentURL to URL of current tab of window 1
            if currentURL contains "example.com" then -- Ganti dengan URL yang ingin Anda pantau
                do shell script "pmset sleepnow"
            end if
        end tell
    end try
    delay 5 -- Tunggu 5 detik sebelum memeriksa lagi
end repeat
