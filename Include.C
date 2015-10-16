// C++ includes
#include <string>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

struct DorkyEventIdentifier {
    // this is a workaround for not having unique event id's in MC
    DorkyEventIdentifier (unsigned long int r, unsigned long int e, unsigned long int l);
    unsigned long int run, event, lumi_section;
    bool is_duplicate (const DorkyEventIdentifier &id);
    bool operator < (const DorkyEventIdentifier &) const;
    bool operator == (const DorkyEventIdentifier &) const;
};

bool DorkyEventIdentifier::operator < (const DorkyEventIdentifier &other) const
{
    if (run != other.run)
        return run < other.run;
    if (event != other.event)
        return event < other.event;
    if (lumi_section != other.lumi_section)
        return lumi_section < other.lumi_section;
    return false;
}

bool DorkyEventIdentifier::operator == (const DorkyEventIdentifier &other) const
{
    if (run != other.run)
        return false;
    if (event != other.event)
        return false;
    return true;
}
std::set<DorkyEventIdentifier> already_seen;
bool is_duplicate (const DorkyEventIdentifier &id)
{
    std::pair<std::set<DorkyEventIdentifier>::const_iterator, bool> ret =
        already_seen.insert(id);
    return !ret.second;
}

void clear_seen() { 
    // if we run over data multiple times, later runs
    // get ignored since the already_seen set is never
    // cleared, so put this before running every time
    already_seen.clear();
}

