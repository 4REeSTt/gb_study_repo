# It must work, at -c | tail commant to run is /usr/sbin... , but for some reason my PC didnt shutdown(tried diferent methods with at, didnt work)
echo '/usr/sbin/shutdown -r now' | at 12:45 
