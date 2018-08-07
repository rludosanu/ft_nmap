docker build -t ft_nmap .
docker run -it --rm --name ft_nmap -v $(PWD):/ft_nmap ft_nmap
