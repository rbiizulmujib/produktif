set monitoredSites to {"instagram.com", "twitter.com", "x.com", "javmovs.com", "missav.com", "njav.com", "vjav.com", "eporner.com", "facebook.com"} -- Tambahkan situs yang ingin dipantau di sini

repeat
    try
        tell application "Safari"
            set currentURL to URL of current tab of window 1
            repeat with site in monitoredSites
                if currentURL contains site then
                    close current tab of window 1
                    -- do shell script "pmset sleepnow"
                end if
            end repeat
        end tell
    end try
    delay 0.5 -- Tunggu 5 detik sebelum memeriksa lagi
end repeat
