
cd ../..

git add Yellow/final





set /A d = %DATE:~0,2%
set /A v = %DATE:~3,1%

if %v% == 0 (git commit -m "v%DATE:~4,1%.%d%") else (git commit -m "v%DATE:~3,2%.%d%")


git push
cd Yellow/final