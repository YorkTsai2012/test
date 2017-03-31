#/bin/sh

if [ $# -lt 1 ]; then
    echo "usage: $0 ip"
    exit 1
fi

ip="$1"

database="ufs_meta"
tablename="t_filesystem"
echo "create table $database.$tablename"
mysql -h $ip -uucloud -pucloud.cn << eof
use $database;
CREATE TABLE IF NOT EXISTS $tablename (
    volume_id varchar(255) NOT NULL,
    volume_name varchar(255) NOT NULL,
    volume_size bigint(20) unsigned NOT NULL,
    resource_id varchar(255) NOT NULL,
    top_organization_id int(10) unsigned NOT NULL,
    organization_id int(10) unsigned NOT NULL,
    account_id int(10) unsigned NOT NULL,
    create_time int(10) unsigned NOT NULL,
    update_time timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    valid tinyint(1) NOT NULL,
    fs_id bigint(20) unsigned NOT NULL ,
    root_entry_key bigint(20) unsigned NOT NULL,
    root_name varchar(255) NOT NULL,
    rtmax int(10) unsigned NOT NULL,
    rtpref int(10) unsigned NOT NULL,
    rtmult int(10) unsigned NOT NULL,
    wtmax int(10) unsigned NOT NULL,
    wtpref int(10) unsigned NOT NULL,
    wtmult int(10) unsigned NOT NULL,
    dtpref int(10) unsigned NOT NULL,
    maxfilesize bigint(10) unsigned NOT NULL,
    time_delta_s int(10) unsigned NOT NULL,
    time_delta_ns int(10) unsigned NOT NULL,
    properties int(10) unsigned NOT NULL,
    linkmax int(10) unsigned NOT NULL,
    name_max int(10) unsigned NOT NULL,
    no_trunc tinyint(1) NOT NULL,
    chown_restricted tinyint(1) NOT NULL,
    case_insensitive tinyint(1) NOT NULL,
    case_preserving  tinyint(1) NOT NULL,
    PRIMARY KEY (volume_id),
    UNIQUE KEY (fs_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
eof
