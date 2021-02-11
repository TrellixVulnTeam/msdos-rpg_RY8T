import requests
ini = open("../settings.ini","r")
f = open("python.file","w")
ver = ini.readline()
response = requests.get("https://glgele.github.io/DreamBorderX/xml/MSDos-RPG.VersionCheck.file")
f.write(response.text)
f.close()
ini.close()
print("updateChecker启动成功")