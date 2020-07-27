# WhizniumSBE

The Whiznium Service Builder's Edition, finally as Open Source Software project.

## How it works

![](_exp/sbe.png)

## Dependencies

WhizniumSBE-generated code is free from any use restrictions, except for the obvious fact that no exclusivity for the resulting coding style and / or web UI look & feel can be claimed by any user.

### WhizniumSBE-backed projects

Only few libraries are required, all of which are equipped with permissive licenses, allowing to deploy WhizniumSBE-backed software both as Open Source Software and commercially.

- [Gnome libxml2](http://xmlsoft.org), to serlialize / deserialize XML blocks both for HTTP(S) transfers and preferences files
- [GNU Libmicrohttpd](https://www.gnu.org/software/libmicrohttpd), a lightweight multi-threading-capable web-server library included in every WhizniumSBE-backed project
- [libcurl](https://curl.haxx.se/libcurl), to handle inter-executable master / slave XML-over-HTTP(S) communication. Required only for large WhizniumSBE-backed projects, such as WhizniumSBE/DBE themselves, where functionality is distributed across a central engine executable and multiple operation engine executables

Furthermore, at least one DBMS client library is needed; options include:

- [SQLite 3](https://www.sqlite.org/index.html), the only server-less solution supported, best suited for embedded software projects
- [MariaDB](https://mariadb.org), the open source branch of MySQL
- [MySQL](https://www.mysql.com), the most widely-spread DBMS provided by Oracle
- [PostgreSQL](https://www.postgresql.org)

In some applications so far, WhizniumSBE-backed projects needed either OPC UA or DDS connectivity. While code generated to use the corresponding library API's is license-free, the corresponding SDK's are commercial software:

- [Matrikon FLEX OPC UA SDK](https://www.matrikonopc.com/campaigns/opc-ua/matrikon-opc-ua-sdk.aspx)
- [rti Connext DDS](https://www.rti.com/products)

### WhizniumSBE itself

WhizniumSBE is a WhizniumSBE-backed project. Accordingly, it requires libxml2, GNU Libmicrohttpd and libcurl to work. Our preferred choice for DBMS is MariaDB.

## Resources for now

### Use cases

- FabSight: montioring of industrial appliances, [.pdf datasheet](https://mpsitech-public.s3.eu-central-1.amazonaws.com/fabsight.pdf) and [YouTube video](https://youtu.be/Z-NvdSHfAvM) showing device in action including .NET API access
- The ICARUS detector: a [European robotics research project](http://www.fp7-icarus.eu) alongside which WhizniumSBE/DBE developed lots of its functionality, [.pdf datasheet](https://mpsitech-public.s3.eu-central-1.amazonaws.com/icarus.pdf)
- Multi-spectral detector: developed from the ICARUS detector, combines stereo vision with a thermal imager and a laser mounted on a tilt/pan unit. [.pdf code walk-through](https://mpsitech-public.s3.eu-central-1.amazonaws.com/Thermal_Imager_Data_Path.pdf) available

### Reference / documentation

### Marketing material

Most of these publications pre-date Whiznium's Open Source era.

## Upcoming documentation

- The Whiznium book (draft available [here](https://mpsitech-public.s3.eu-central-1.amazonaws.com/book.pdf)), offering an introduction to WhizniumSBE/DBE by means of a handy use case in the firsrt chapters, but also with a complete reference in the later chapters

## Related Repositories

- The [WhizniumSBE core library](https://github.com/mpsitech/sbecore-WhizniumSBE-Core-Library)
- [WhizniumDBE](https://github.com/mpsitech/wdbe-WhizniumDBE), Whiznium Device Builder's Edition, counterpart for developing RTL projects with VHDL as main programming language
