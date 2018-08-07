# ft_nmap

## Synopsis

```
./ft_nmap
	[--help]
	[--ports [range][list]]
	[--ip [host]]
	[--file [source]]
	[--speedup [threads]]
	[--scans [types]]
	[--verbose]
	[--max-retries [retries]]
	[--scan-delay [delay]]
	[--decoy [host]]
	[--open]
```

## Usage

```
--help
	Diplay usage

--ports [range][list]
	Ports to scan. By range [5-15] or individualy [1 8].

--ip [host]
	FQDN or IPV4 address to scan.

--file [source]
	File containing a list of FQDN or IPV4 address to scan (max 1024).

--speedup [threads]
	Number of parallel threads to use (max 250)

--scans [types]
	Scan types to perfom [SYN NULL FIN XMAS ACK UDP]

--verbose
	Verbose output

--max-retries [retires]
	Number of port scan probe retransmissions

--scan-delay [delay]
	Delay between probes in seconds

--decoy [host]
	Decoy FQDN or IPV4 address to send from

--open
	Show open ports only
```
