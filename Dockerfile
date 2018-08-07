# Docker image for ft_traceroute
FROM ubuntu

RUN apt-get update \
    && apt-get install -y vim build-essential nmap libpcap0.8-dev

WORKDIR /ft_nmap
CMD bash
